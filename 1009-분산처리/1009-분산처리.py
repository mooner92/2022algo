n = int(input())
for i in range(n):
    a, b = map(int, input().split())
    b %= 120
    a %= 10
    c = a**b
    print(c % 10)
