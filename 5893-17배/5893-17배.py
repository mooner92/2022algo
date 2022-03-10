n = int(input())
#2진수를 10진수로 변환
n = int(str(n), 2)
#17배
n *= 17
#2진수로 출력
print(bin(n)[2:])