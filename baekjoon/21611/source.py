import sys
from copy import deepcopy

input = sys.stdin.readline

n, m = map(int, input().split())
data = [list(map(int, input().split())) for _ in range(n)]
spell = [list(map(int, input().split())) for _ in range(m)]
board = [0] * n * n

def stg():
    bp = 1
    di = [(0, -1), (1, 0), (0, 1), (-1, 0)]
    cd = cn = 0
    dn = 1
    cx, cy = n//2, n//2
    while True:
        if not cx and not cy: break
        x, y = di[cd]
        cx += x
        cy += y
        cn+=1
        board[bp] = data[cx][cy]
        bp += 1
        if cn == dn:
            cn = 0
            cd = (cd+1)%4
            if not cd%2:
                dn += 1

stg()

dd = [0, 2, 1, 3]
ans = [0] * 4

def bliz(d, s):
    cur = 0
    rcnt = 0
    scnt = 0
    while scnt < s:
        cd = 2 * (rcnt//4 + 1)
        if not rcnt%4: cur += cd-1
        else: cur += cd
        rcnt += 1
        if cur >= n*n: break
        if rcnt%4==dd[d-1]:
            scnt+=1
            board[cur] = 0

def move():
    pt = 1
    for i in range(1, n*n):
        if board[i]:
            if pt != i:
                board[pt] = board[i]
                board[i] = 0
            pt += 1

def expl():
    ecnt = 0
    cn = -1
    cnt = 0
    for i in range(1, n*n):
        if board[i] == cn:
            cnt+=1
        else:
            if cnt >= 4:
                for j in range(1, cnt+1):
                    board[i-j] = 0
                ecnt += cnt
                ans[cn] += cnt
            cn = board[i]
            cnt = 1
    return ecnt

def tran():
    global board
    nb = [0] * n * n
    np = 1
    cn = board[1]
    cnt = 1
    for i in range(2, n*n):
        if board[i] == cn:
            cnt+=1
        else:
            if np >= n*n: break
            nb[np] = cnt
            np += 1
            if np >= n*n: break
            nb[np] = cn
            np += 1
            cn = board[i]
            cnt = 1
    board = deepcopy(nb)

for d, s in spell:
    bliz(d, s)
    move()
    while(expl()):
        move()
    tran()
    
print(ans[1]+ans[2]*2+ans[3]*3)
