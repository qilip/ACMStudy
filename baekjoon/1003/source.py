import sys

input = sys.stdin.readline

zro_cnt = [0] * 50
one_cnt = [0] * 50

zro_cnt[0] = 1
one_cnt[1] = 1

def fibo(n):
    if zro_cnt[n]:
        return zro_cnt[n], one_cnt[n]
    if n == 0:
        return 1, 0
    if n == 1:
        return 0, 1
    zro_cnt[n], one_cnt[n] = fibo(n-1)[0] + fibo(n-2)[0], fibo(n-1)[1] + fibo(n-2)[1]
    return zro_cnt[n], one_cnt[n]

t = int(input())
for _ in range(t):
    n = int(input())
    fibo(n)
    print(zro_cnt[n], one_cnt[n])
