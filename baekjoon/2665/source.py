import sys
from collections import deque

input = sys.stdin.readline

n = int(input())
data = [list(map(int, input().rstrip())) for _ in range(n)]

q = deque()
visited = [[False] * n for _ in range(n)]
q.append((0, 0, 0))

while q:
    x, y, c = q.popleft()
    if x == n - 1 and y == n - 1:
        print(c)
        break
    for dx, dy in ((1, 0), (-1, 0), (0, 1), (0, -1)):
        nx, ny = x + dx, y + dy
        if 0 <= nx < n and 0 <= ny < n and not visited[nx][ny]:
                if data[nx][ny] == 1:
                    q.appendleft((nx, ny, c))
                else:
                    q.append((nx, ny, c+1))
                visited[nx][ny] = True
