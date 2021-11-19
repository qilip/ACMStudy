import sys

input = sys.stdin.readline

n, m = map(int, input().split())
d = {}

for _ in range(n):
    d[input().rstrip()] = 1
ans = []
for _ in range(m):
    s = input().rstrip()
    if s in d: ans.append(s)

ans.sort()
print(len(ans))
print(*ans, sep="\n")
