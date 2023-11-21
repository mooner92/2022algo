import torch
from PIL import Image
from pathlib import Path
import os
import sys

if __name__ == "__main__":
    # YOLOv5 모델을 로드합니다.
    model = torch.hub.load("ultralytics/yolov5:master", "yolov5s", pretrained=False)
    # 학습된 가중치 파일을 로드합니다.
    model.load_state_dict(torch.load("/home/ubuntu/pyfile", map_location="cpu"))
    # 모델을 추론 모드로 설정합니다.
    model.eval()

    # 이미지 파일 경로
    image_path = sys.argv[1]

    # 이미지를 모델에 전달하여 객체 감지 수행
    results = model(image_path)

    # 결과 이미지 저장할 디렉토리 경로
    output_directory = "/home/ubuntu/obok_backend_serv/build/libs/images/deep_images"
    os.makedirs(output_directory, exist_ok=True)  # 디렉토리 생성

    # 결과 이미지 파일 경로
    output_image_path = os.path.join(output_directory, "result_image.jpg")

    # 결과 이미지 저장
    results.show(save_path=output_image_path)
    print(output_image_path)
