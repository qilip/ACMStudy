import sys
from collections import deque
from copy import deepcopy

input = sys.stdin.readline

n, q = map(int, input().split())
g = [list(map(int, input().split())) for _ in range(2**n)]
l = list(map(int, input().split()))

def storm(w):
    global g
    for i in range(0, 2**n, w):
        for j in range(0, 2**n, w):
            sg = [k[j:j+w] for k in g[i:i+w]]
            sg = [list(s) for s in zip(*sg[::-1])]
            for q in range(w):
                for p in range(w):
                    g[i+q][j+p] = sg[q][p]

def fire():
    global g
    ng = deepcopy(g)
    for i in range(2**n):
        for j in range(2**n):
            cnt = 0
            for x, y in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                if i+x < 0 or i+x >= 2**n or j+y < 0 or j+y >= 2**n:
                    continue
                if g[i+x][j+y]:
                    cnt += 1
            if cnt < 3: ng[i][j] = max(g[i][j]-1, 0)
    g = deepcopy(ng)
    return

def bfs():
    global g
    ans = 0
    color = [[0] * 2**n for _ in range(2**n)]
    ccnt = 0
    for i in range(2**n):
        for j in range(2**n):
            if color[i][j] or not g[i][j]: continue
            ccnt += 1
            cnt = 1
            color[i][j] = ccnt
            q = deque([(i, j)])
            while q:
                x, y = q.popleft()
                for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                    if x+dx < 0 or x+dx >= 2**n or y+dy < 0 or y+dy >= 2**n:
                        continue
                    if g[x+dx][y+dy] and not color[x+dx][y+dy]:
                        color[x+dx][y+dy] = ccnt
                        cnt += 1
                        q.append((x+dx, y+dy))
            ans = max(ans, cnt)
    return ans

for i in l:
    storm(2**i)
    fire()

print(sum(map(sum, g)))
print(bfs())
