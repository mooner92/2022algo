import random
import os
import pandas as pd
import numpy as np
from tqdm.auto import tqdm
from sklearn.preprocessing import LabelEncoder

import torch
import torch.nn as nn
import torch.optim as optim
import torch.nn.functional as F
from torch.utils.data import Dataset, DataLoader

device = torch.device("cuda") if torch.cuda.is_available() else torch.device("cpu")

CFG = {
    "TRAIN_WINDOW_SIZE": 90,  # 90일치로 학습
    "PREDICT_SIZE": 21,  # 21일치 예측
    "EPOCHS": 10,
    "LEARNING_RATE": 1e-4,
    "BATCH_SIZE": 4096,
    "SEED": 41,
}


def seed_everything(seed):
    random.seed(seed)
    os.environ["PYTHONHASHSEED"] = str(seed)
    np.random.seed(seed)
    torch.manual_seed(seed)
    torch.cuda.manual_seed(seed)
    torch.backends.cudnn.deterministic = True
    torch.backends.cudnn.benchmark = True


seed_everything(CFG["SEED"])  # Seed 고정

train_data = pd.read_csv("./train.csv").drop(columns=["ID", "제품"])

# Data Scaling
scale_max_dict = {}
scale_min_dict = {}

for idx in tqdm(range(len(train_data))):
    maxi = np.max(train_data.iloc[idx, 4:])
    mini = np.min(train_data.iloc[idx, 4:])

    if maxi == mini:
        train_data.iloc[idx, 4:] = 0
    else:
        train_data.iloc[idx, 4:] = (train_data.iloc[idx, 4:] - mini) / (maxi - mini)

    scale_max_dict[idx] = maxi
    scale_min_dict[idx] = mini

# Label Encoding
label_encoder = LabelEncoder()
categorical_columns = ["대분류", "중분류", "소분류", "브랜드"]

for col in categorical_columns:
    label_encoder.fit(train_data[col])
    train_data[col] = label_encoder.transform(train_data[col])


def make_train_data(
    data, train_size=CFG["TRAIN_WINDOW_SIZE"], predict_size=CFG["PREDICT_SIZE"]
):
    """
    학습 기간 블럭, 예측 기간 블럭의 세트로 데이터를 생성
    data : 일별 판매량
    train_size : 학습에 활용할 기간
    predict_size : 추론할 기간
    """
    num_rows = len(data)
    window_size = train_size + predict_size

    input_data = np.empty(
        (
            num_rows * (len(data.columns) - window_size + 1),
            train_size,
            len(data.iloc[0, :4]) + 1,
        )
    )
    target_data = np.empty(
        (num_rows * (len(data.columns) - window_size + 1), predict_size)
    )

    for i in tqdm(range(num_rows)):
        encode_info = np.array(data.iloc[i, :4])
        sales_data = np.array(data.iloc[i, 4:])

        for j in range(len(sales_data) - window_size + 1):
            window = sales_data[j : j + window_size]
            temp_data = np.column_stack(
                (np.tile(encode_info, (train_size, 1)), window[:train_size])
            )
            input_data[i * (len(data.columns) - window_size + 1) + j] = temp_data
            target_data[i * (len(data.columns) - window_size + 1) + j] = window[
                train_size:
            ]

    return input_data, target_data


def make_predict_data(data, train_size=CFG["TRAIN_WINDOW_SIZE"]):
    """
    평가 데이터(Test Dataset)를 추론하기 위한 Input 데이터를 생성
    data : 일별 판매량
    train_size : 추론을 위해 필요한 일별 판매량 기간 (= 학습에 활용할 기간)
    """
    num_rows = len(data)

    input_data = np.empty((num_rows, train_size, len(data.iloc[0, :4]) + 1))

    for i in tqdm(range(num_rows)):
        encode_info = np.array(data.iloc[i, :4])
        sales_data = np.array(data.iloc[i, -train_size:])

        window = sales_data[-train_size:]
        temp_data = np.column_stack(
            (np.tile(encode_info, (train_size, 1)), window[:train_size])
        )
        input_data[i] = temp_data

    return input_data


train_input, train_target = make_train_data(train_data)
test_input = make_predict_data(train_data)

# Train / Validation Split
data_len = len(train_input)
val_input = train_input[-int(data_len * 0.2) :]
val_target = train_target[-int(data_len * 0.2) :]
train_input = train_input[: -int(data_len * 0.2)]
train_target = train_target[: -int(data_len * 0.2)]

train_input.shape, train_target.shape, val_input.shape, val_target.shape, test_input.shape


class CustomDataset(Dataset):
    def __init__(self, X, Y):
        self.X = X
        self.Y = Y

    def __getitem__(self, index):
        if self.Y is not None:
            return torch.Tensor(self.X[index]), torch.Tensor(self.Y[index])
        return torch.Tensor(self.X[index])

    def __len__(self):
        return len(self.X)


train_dataset = CustomDataset(train_input, train_target)
train_loader = DataLoader(
    train_dataset, batch_size=CFG["BATCH_SIZE"], shuffle=True, num_workers=0
)

val_dataset = CustomDataset(val_input, val_target)
val_loader = DataLoader(
    val_dataset, batch_size=CFG["BATCH_SIZE"], shuffle=False, num_workers=0
)


class BaseModel(nn.Module):
    def __init__(self, input_size=5, hidden_size=512, output_size=CFG["PREDICT_SIZE"]):
        super(BaseModel, self).__init__()
        self.hidden_size = hidden_size
        self.lstm = nn.LSTM(input_size, hidden_size, batch_first=True)
        self.fc = nn.Sequential(
            nn.Linear(hidden_size, hidden_size // 2),
            nn.ReLU(),
            nn.Dropout(),
            nn.Linear(hidden_size // 2, output_size),
        )

        self.actv = nn.ReLU()

    def forward(self, x):
        # x shape: (B, TRAIN_WINDOW_SIZE, 5)
        batch_size = x.size(0)
        hidden = self.init_hidden(batch_size, x.device)

        # LSTM layer
        lstm_out, hidden = self.lstm(x, hidden)

        # Only use the last output sequence
        last_output = lstm_out[:, -1, :]

        # Fully connected layer
        output = self.actv(self.fc(last_output))

        return output.squeeze(1)

    def init_hidden(self, batch_size, device):
        # Initialize hidden state and cell state
        return (
            torch.zeros(1, batch_size, self.hidden_size, device=device),
            torch.zeros(1, batch_size, self.hidden_size, device=device),
        )


def train(model, optimizer, train_loader, val_loader, device):
    model.to(device)
    criterion = nn.MSELoss().to(device)
    best_loss = 9999999
    best_model = None

    for epoch in range(1, CFG["EPOCHS"] + 1):
        model.train()
        train_loss = []
        train_mae = []
        for X, Y in tqdm(iter(train_loader)):
            X = X.to(device)
            Y = Y.to(device)

            optimizer.zero_grad()

            output = model(X)
            loss = criterion(output, Y)

            loss.backward()
            optimizer.step()

            train_loss.append(loss.item())

        val_loss = validation(model, val_loader, criterion, device)
        print(
            f"Epoch : [{epoch}] Train Loss : [{np.mean(train_loss):.5f}] Val Loss : [{val_loss:.5f}]"
        )

        if best_loss > val_loss:
            best_loss = val_loss
            best_model = model
            print("Model Saved")
    return best_model


def validation(model, val_loader, criterion, device):
    model.eval()
    val_loss = []

    with torch.no_grad():
        for X, Y in tqdm(iter(val_loader)):
            X = X.to(device)
            Y = Y.to(device)

            output = model(X)
            loss = criterion(output, Y)

            val_loss.append(loss.item())
    return np.mean(val_loss)


model = BaseModel()
optimizer = torch.optim.Adam(params=model.parameters(), lr=CFG["LEARNING_RATE"])
infer_model = train(model, optimizer, train_loader, val_loader, device)

test_dataset = CustomDataset(test_input, None)
test_loader = DataLoader(
    test_dataset, batch_size=CFG["BATCH_SIZE"], shuffle=False, num_workers=0
)


def inference(model, test_loader, device):
    predictions = []

    with torch.no_grad():
        for X in tqdm(iter(test_loader)):
            X = X.to(device)

            output = model(X)

            # 모델 출력인 output을 CPU로 이동하고 numpy 배열로 변환
            output = output.cpu().numpy()

            predictions.extend(output)

    return np.array(predictions)


pred = inference(infer_model, test_loader, device)

# 추론 결과를 inverse scaling
for idx in range(len(pred)):
    pred[idx, :] = (
        pred[idx, :] * (scale_max_dict[idx] - scale_min_dict[idx]) + scale_min_dict[idx]
    )

# 결과 후처리
pred = np.round(pred, 0).astype(int)

pred.shape

submit = pd.read_csv("./sample_submission.csv")
submit.head()

submit.iloc[:, 1:] = pred
submit.head()

submit.to_csv("./baseline_submit.csv", index=False)
