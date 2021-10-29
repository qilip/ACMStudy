import sys
from collections import deque

input = sys.stdin.readline

n, m = map(int, input().split())
g = [list(map(int, input().split())) for _ in range(n)]

def block():
    global g
    visit = [[0] * n for _ in range(n)]
    group = []
    for i in range(n):
        for j in range(n):
            if visit[i][j] or g[i][j]<1: continue
            q = deque()
            cg = []
            cg.append((i, j))
            rcnt = 0
            visit[i][j] = True
            q.append((i, j))
            while q:
                x, y = q.popleft()
                for nx, ny in [(x-1, y), (x, y+1), (x+1, y), (x, y-1)]:
                    if nx<0 or nx==n or ny<0 or ny==n or visit[nx][ny]: continue
                    if g[nx][ny]==0 or g[nx][ny]==g[i][j]:
                        visit[nx][ny] = True
                        if not g[nx][ny]: rcnt += 1
                        cg.append((nx, ny))
                        q.append((nx, ny))
            if(len(cg)>1): group.append((len(cg), rcnt, i, j, cg))
            for a in range(n):
                for b in range(n):
                    if not g[a][b]: visit[a][b] = 0
    if not group: return 0
    group.sort(reverse=True)
    for a, b in group[0][4]:
        g[a][b] = -2
    return len(group[0][4])

def grav():
    for j in range(n):
        for i in range(n-1)[::-1]:
            if g[i][j]>-1:
                for k in range(i+1, n):
                    if g[k][j]!=-2: break
                    g[k-1][j], g[k][j] = g[k][j], g[k-1][j]

ans = 0

while True:
    cur = block()
    if not cur: break
    ans += cur**2
    grav()
    g = [list(l[::-1]) for l in zip(*g[::-1])][::-1]
    grav()

print(ans)
