import sys

input = sys.stdin.readline

n = int(input())
dist = [[1e9] * n for _ in range(n)]
for i in range(n):
    dist[i][i] = 0
while True:
    a, b = map(int, input().split())
    if a==b==-1: break
    dist[a-1][b-1] = 1
    dist[b-1][a-1] = 1

for k in range(n):
    for i in range(n):
        for j in range(n):
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
m = min(map(max, dist))
l = []
for i in range(n):
    if max(dist[i]) == m:
        l.append(i+1)
print(m, len(l))
print(*l)
