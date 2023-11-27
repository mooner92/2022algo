import torch
from PIL import Image
from pathlib import Path
import os
import sys

if __name__ == "__main__":
    # YOLOv5 모델을 로드합니다.
    model = torch.hub.load("ultralytics/yolov5:master", "yolov5s", pretrained=False)
    # 학습된 가중치 파일을 로드합니다.
    model.load_state_dict(
        torch.load("/home/mooner92/obok/pyfile/best.pt", map_location="cpu")
    )
    # 모델을 추론 모드로 설정합니다.
    model.eval()

    # 이미지 파일 경로
    image_path = "/home/mooner92/obok/images/231125/8461428497997.jpg"

    # 이미지를 모델에 전달하여 객체 감지 수행
    results = model(image_path)

    # 결과 이미지 저장할 디렉토리 경로
    output_directory = "/home/mooner92/deep_images"
    os.makedirs(output_directory, exist_ok=True)  # 디렉토리 생성
    od_slice = image_path[19:]
    # 결과 이미지 파일 경로
    output_image_path = os.path.join(output_directory, "{od_slice}")

    # 결과 이미지 저장
    results.show(save_path=output_image_path)
    print(output_image_path)
#####
