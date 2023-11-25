import subprocess
import cv2

command = [
    "python3",
    "/home/ubuntu/yolov5/detect.py",
    "--weights",
    "/home/ubuntu/pyfile/best.pt",
    "--img",
    "320",
    "--conf",
    "0.5",
    "--source",
    "/home/ubuntu/images/231123/17193891798017.jpg",
    "--save-txt",
    "--save-conf",
    "--view-img",
    "/home/ubuntu/deep_image",
]
# 객체 감지 결과 이미지와 박스 정보가 있다고 가정
result_image = subprocess.run(command)
output_path = "/home/ubuntu/deep_image/output.jpg"  # 저장할 경로 및 파일 이름

# 이미지 저장
cv2.imwrite(output_path, result_image)

# 실행할 명령어


# subprocess를 사용하여 명령어 실행

######
