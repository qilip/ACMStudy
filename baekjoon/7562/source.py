import sys
from collections import deque

input = sys.stdin.readline

d = [(2, -1), (2, 1), (1, 2), (1, -2), (-1, 2), (-1, -2), (-2, -1), (-2, 1)]

t = int(input())
for _ in range(t):
    n = int(input())
    kx, ky = map(int, input().split())
    ex, ey = map(int, input().split())
    visit = [[0] * n for _ in range(n)]
    visit[kx][ky] = 1
    q = deque([(kx, ky, 0)])
    while q:
        cx, cy, cost = q.popleft()
        if cx==ex and cy==ey:
            print(cost)
            break
        for dx, dy in d:
            nx, ny = cx+dx, cy+dy
            if 0<=nx<n and 0<=ny<n and not visit[nx][ny]:
                q.append((nx, ny, cost+1))
                visit[nx][ny] = 1
