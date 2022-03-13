A,B,C = list(map(int,input().split()))


def getMod(A,B):
    if not B:
        return 1

    value = getMod(A, B // 2) ** 2

    if B % 2: value *= A % C

    return value % C

print(getMod(A,B))

# https://openhodu.tistory.com/m/2  를 참고함#