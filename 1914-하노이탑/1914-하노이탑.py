N = int(input())

def hanoi(n,start,final,middle):
    if n == 1:
        print(start,final)
    else:
        hanoi(n-1,start,middle,final)
        print(start,final) # 제일 큰 원반 move
        hanoi(n-1,middle,final,start)

print(2**N-1)
if N <= 20:
    hanoi(N,1,3,2)