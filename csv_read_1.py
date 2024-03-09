import csv
from pyproj import Proj, transform
import numpy as np
import pandas as pd

# Projection 정의
# UTM-K
proj_UTMK = Proj(init="epsg:5174")  # UTM-K(Bassel) 도로명주소 지도 사용 중

# WGS1984
proj_WGS84 = Proj(init="epsg:4326")  # Wgs84 경도/위도, GPS사용 전지구 좌표

# CSV 파일의 경로
csv_file_path = (
    "/Users/mooner92/Downloads/병원좌표_1.csv"  # 여기에 실제 파일 경로를 넣어주세요
)

# 빈 2차원 배열 생성
data = []

# CSV 파일 열기
with open(csv_file_path, "r") as csv_file:
    csv_reader = csv.reader(
        csv_file, delimiter=","
    )  # 콤마로 구분된 파일이므로 delimiter를 ','로 설정
    for row in csv_reader:
        # 각 행을 float 형식으로 변환하여 2차원 배열에 추가
        row_float = [float(val) for val in row]
        data.append(row_float)

# UTM-K -> WGS84 샘플
for row in data:
    x1, y1 = row[0], row[1]
    x2, y2 = transform(proj_UTMK, proj_WGS84, x1, y1)
    print(str(y2) + "," + str(x2))
##
###
