import sys

input = sys.stdin.readline

n = int(input())
g = [list(map(int, input().split())) for _ in range(n)]
wind = [
    [0, 0, 2, 0, 0],
    [0, 10, 7, 1, 0],
    [5, 0, 0, 0, 0],
    [0, 10, 7, 1, 0],
    [0, 0, 2, 0, 0],
]
cx = cy = n//2
cdi = cdc = 0
cdd = 1
d = [[0, -1], [1, 0], [0, 1], [-1, 0]]
ans = 0
turn = 0

def move():
    global cx, cy, cdi, cdc, cdd, turn
    cx += d[cdi][0]
    cy += d[cdi][1]
    cdc+=1
    if cdd == cdc:
        cdc = 0
        cdi = (cdi+1)%4
        turn = 1
        if not cdi%2:
            cdd += 1

def send():
    al = g[cx][cy]
    tot = 0
    su = 0
    g[cx][cy] = 0
    for i in range(-2, 3):
        for j in range(-2, 3):
            cr = al * wind[i+2][j+2] // 100
            tot += cr
            if cx+i>=0 and cy+j>=0 and cx+i<n and cy+j<n: g[cx+i][cy+j] += cr
            else: su += cr
    ax = cx+d[(cdi+4-turn)%4][0]
    ay = cy+d[(cdi+4-turn)%4][1]
    if ax>=0 and ay>=0 and ax<n and ay<n:
        g[ax][ay] += al - tot
    else: su += al - tot
    return su

while cx!=0 or cy!=-1:
    move()
    ans += send()
    if turn:
        wind = [list(l[::-1]) for l in zip(*wind[::-1])][::-1]
        turn = 0

print(ans)