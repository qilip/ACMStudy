import sys
from collections import deque

input = sys.stdin.readline

m, n = map(int, input().split())
data = [list(map(int, input().rstrip())) for _ in range(n)]
visited = [[False] * m for _ in range(n)]

q = deque()
q.append((0, 0, 0))

while q:
    x, y, cnt = q.popleft()
    if x == n - 1 and y == m - 1:
        print(cnt)
        break
    for dx, dy in ((0, 1), (0, -1), (1, 0), (-1, 0)):
        nx, ny = x + dx, y + dy
        if 0 <= nx < n and 0 <= ny < m and not visited[nx][ny]:
            visited[nx][ny] = True
            if data[nx][ny]:
                q.append((nx, ny, cnt + 1))
            else:
                q.appendleft((nx, ny, cnt))
