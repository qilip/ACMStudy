import sys
from collections import deque

input = sys.stdin.readline

t = int(input())
for _ in range(t):
    m, n, k = map(int, input().split())
    data = [list(map(int, input().split())) for _ in range(k)]
    board = [[0] * m for _ in range(n)]
    for x, y in data:
        board[y][x] = 1
    d = [(0, -1), (0, 1), (1, 0), (-1, 0)]

    count = 0
    visit = [[0] * m for _ in range(n)]

    def bfs(sx, sy):
        q = deque([(sx, sy)])
        visit[sx][sy] = 1
        while q:
            cx, cy = q.popleft()
            for x, y in d:
                nx, ny = cx+x, cy+y
                if 0<=nx<n and 0<=ny<m and not visit[nx][ny] and board[nx][ny]:
                    q.append((nx, ny))
                    visit[nx][ny] = 1

    for i in range(n):
        for j in range(m):
            if board[i][j] and not visit[i][j]:
                count+=1
                bfs(i, j)
    print(count)
