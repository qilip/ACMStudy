import sys
import math
input = sys.stdin.readline

n, l = map(int, input().split())
data = [list(map(int, input().split())) for _ in range(n)]
data.sort()

cur = 0
cnt = 0
for a, b in data:
    if cur < a:
        cnt += 1
        cur = a+l
    if cur >= b: continue
    d = math.ceil((b-cur)/l)
    cnt += d
    cur += d*l

print(cnt)
