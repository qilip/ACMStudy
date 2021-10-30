import sys
from collections import deque

input = sys.stdin.readline

n, m, k = map(int, input().split())
ball = [list(map(int, input().split())) for _ in range(m)]
board = [[[] for _ in range(n)] for _ in range(n)]
d = [(-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1)]

for i in ball:
    i[0] -= 1
    i[1] -= 1

for c in ball:
    board[c[0]][c[1]].append([c[2], c[3], c[4]])

def move():
    global board
    newb = [[[] for _ in range(n)] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            for k in board[i][j]:
                nx, ny = i+d[k[2]][0]*k[1], j+d[k[2]][1]*k[1]
                newb[nx%n][ny%n].append(k)
    board = newb

def splt():
    global ball
    for i in range(n):
        for j in range(n):
            ma = 0
            sp = 0
            cnt = 0
            dr = [0, 0]
            for cur in board[i][j]:
                ma += cur[0]
                sp += cur[1]
                cnt += 1
                dr[cur[2]%2] += 1
            if cnt < 2: continue
            board[i][j].clear()
            if not ma//5: continue
            ma //= 5
            sp //= cnt
            nd = []
            if dr[0] and dr[1]: nd = [1, 3, 5, 7]
            else: nd = [0, 2, 4, 6]
            for dd in nd:
                board[i][j].append([ma, sp, dd])

for _ in range(k):
    move()
    splt()

ans = 0
for i in range(n):
    for j in range(n):
        for k in board[i][j]:
            ans += k[0]
print(ans)
