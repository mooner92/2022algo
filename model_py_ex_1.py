import torch
from pathlib import Path
from PIL import Image
import os
import sys

if __name__ == "main":
    # YOLOv5 모델을 로드합니다.
    model = torch.hub.load("ultralytics/yolov5:master", "yolov5s", pretrained=False)
    # 학습된 가중치 파일을 로드합니다.
    model.load_state_dict(torch.load("/home/ubuntu/pyfile", map_location="cpu"))
    # 모델을 추론 모드로 설정합니다.
    model.eval()

    # 이미지 디렉토리 경로
    image_directory = sys.argv[1]
    # 이미지 파일 리스트를 가져옵니다.
    image_files = os.listdir(image_directory)

    # 결과 이미지를 저장할 디렉토리 경로
    output_directory = "/home/ubuntu/obok_backend_serv/build/libs/images/deep_images"
    Path(output_directory).mkdir(parents=True, exist_ok=True)  # 디렉토리 생성

    # 각 이미지에 대한 객체 감지 수행 및 결과 저장
    for image_file in image_files:
        # 이미지 파일 경로
        image_path = os.path.join(image_directory, image_file)
        # 이미지를 모델에 전달하여 객체 감지 수행
        results = model(image_path)
        # 결과 이미지 저장
        output_image_path = os.path.join(output_directory, image_file)
        results.show(save_path=output_image_path)
    print("{output_directory}")
