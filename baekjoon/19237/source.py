import sys

input = sys.stdin.readline

n, m, k = map(int,input().split())
nn = [list(map(int,input().split())) for _ in range(n)]
shk_dir = list(map(int,input().split()))
shk_pri = [[list(map(int,input().split())) for _ in range(4)] for _ in range(m)]

xy = [(0, 0), (-1, 0), (1, 0), (0, -1), (0, 1)]

shks = list(range(1, m+1))
shk_pos = [(0, 0)] * (m+1)
board = [[(0, 0)] * n for _ in range(n)]

def find(c):
    for i in range(n):
        for j in range(n):
            if c==nn[i][j]: return i, j

def init():
    for i in range(1, m+1):
        shk_pos[i] = x, y = find(i)
        board[x][y] = (i, 0)

def clear(t):
    for i in range(n):
        for j in range(n):
            if board[i][j][0] and board[i][j][1] + k <= t:
                board[i][j] = (0, 0)

def run(t):
    global shks
    for c in shks:
        x, y = shk_pos[c]
        nxt = (-1, -1)
        nxt_dir = 0
        for i in range(4):
            dx, dy = xy[shk_pri[c-1][shk_dir[c-1]-1][i]]
            nx, ny = x + dx, y + dy
            if nx < 0 or ny < 0 or nx == n or ny == n: continue
            if board[nx][ny] == (0, 0):
                nxt = (nx, ny)
                nxt_dir = i
                break
            if nxt[0]==-1 and board[nx][ny][0] == c:
                nxt = (nx, ny)
                nxt_dir = i
        shk_dir[c-1] = shk_pri[c-1][shk_dir[c-1]-1][nxt_dir]
        shk_pos[c] = nxt
    dic = dict()
    dele = []
    for c in shks:
        if shk_pos[c] not in dic.keys():
            dic[shk_pos[c]] = 1
            board[shk_pos[c][0]][shk_pos[c][1]] = (c, t)
        else:
            dele.append(c)
    shks = list(set(shks) - set(dele))

def solve():
    init()
    for t in range(1, 1001):
        run(t)
        clear(t)
        # print(board)
        if len(shks) == 1:
            print(t)
            return
    print(-1)

solve()
