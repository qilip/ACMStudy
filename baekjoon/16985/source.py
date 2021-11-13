import sys
from itertools import permutations, product
from copy import deepcopy
from collections import deque

input = sys.stdin.readline

board = [list(list(map(int, input().split())) for _ in range(5)) for _ in range(5)]
ans = 99999999

def turn(arr, num):
    for _ in range(num):
        arr = [list(l) for l in zip(*arr[::-1])]
    return arr

def bfs(arr):
    if not arr[0][0][0] or not arr[4][4][4]: return 99999999
    visit = [[[0] * 5 for _ in range(5)] for _ in range(5)]
    visit[0][0][0] = 1
    qu = deque([(0, 0, 0, 0)]) #x, y, z, cost
    while qu:
        x, y, z, cost = qu.popleft()
        for p in [-1, 1]:
            for q, w, e in [(1, 0, 0), (0, 1, 0), (0, 0, 1)]:
                nx, ny, nz = x+q*p, y+w*p, z+e*p
                ncost = cost+1
                if nx==ny==nz==4: return ncost
                if not (0<=nx<5 and 0<=ny<5 and 0<=nz<5): continue
                if not visit[nx][ny][nz] and arr[nx][ny][nz]:
                    visit[nx][ny][nz] = 1
                    qu.append((nx, ny, nz, ncost))
    return 99999999

for cube in permutations(board):
    for cturn in product(*([list(range(4))]*5)):
        ccube = list(cube)
        for i, t in zip(range(5), cturn):
            arr = ccube[i]
            for _ in range(t):
                arr = [list(l) for l in zip(*arr[::-1])]
            ccube[i] = arr
        ans = min(ans, bfs(ccube))
print(-1 if ans==99999999 else ans)
