import sys

input = sys.stdin.readline

n = int(input())
data = [0]
data.extend([float(input()) for _ in range(n)])
nd = [0] * (n+1)
nd[0] = 1

for i in range(1, n+1):
    nd[i] = max(nd[i-1] * data[i], 1)
nd[0] = 0
res = max(data)
if res > 1:
    res = max(res, max(nd))
print("{:.3f}".format(res))
