import os
import subprocess
import sys

# 프로젝트 디렉토리 경로 설정
project_dir = "/home/mooner92/obok/deep_images"
od_address = sys.argv[1]
subprocess.run(
    [
        "python3",
        "/home/mooner92/obok/yolov5/detect.py",
        "--weights",
        "/home/mooner92/obok/pyfile/best.pt",
        "--img",
        "640",
        "--conf",
        "0.01",
        "--source",
        od_address,
        "--save-conf",
        "--line-thickness",
        "4",
        "--save-txt",
        "--project",
        project_dir,
    ]
)

od = od_address[36:-4]
print(f"{od}")
