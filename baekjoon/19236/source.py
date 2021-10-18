import sys
from copy import deepcopy

input = sys.stdin.readline
data = [list(map(int, input().split())) for _ in range(4)]

arr = [[0] * 4 for _ in range(4)]

for i in range(4):
    for j in range(4):
        arr[i][j] = data[i][j*2], data[i][j*2+1]

shk_loc = (0, 0)
fscore = arr[0][0][0]
sf = arr[0][0][1]
arr[0][0] = (0, 0)
dxy = [(-1, 0), (-1, -1), (0, -1), (1, -1), (1, 0), (1, 1), (0, 1), (-1, 1)]

def find_fish(cur):
    for i in range(4):
        for j in range(4):
            if arr[i][j][0] == cur:
                return i, j
    return -1, -1

def fish():
    for i in range(1, 17):
        cx, cy = find_fish(i)
        if cx == -1: continue
        for j in range(8):
            nx, ny = cx + dxy[(arr[cx][cy][1]-1+j)%8][0], cy + dxy[(arr[cx][cy][1]-1+j)%8][1]
            if nx < 0 or nx > 3 or ny < 0 or ny > 3: continue
            if shk_loc == (nx, ny): continue
            arr[cx][cy] = (arr[cx][cy][0], (arr[cx][cy][1] -1 + j) % 8 + 1)
            arr[nx][ny], arr[cx][cy] = arr[cx][cy], arr[nx][ny]
            break

def shk(sx, sy, sd):
    global arr, shk_loc
    ans = 0
    sdxy = dxy[sd-1]
    for i in range(1, 4):
        snx, sny = sx + sdxy[0]*i, sy + sdxy[1]*i
        if snx < 0 or snx > 3 or sny < 0 or sny > 3: break
        if arr[snx][sny][0] == 0: continue
        bak_fish = arr[snx][sny]
        bak_loc = shk_loc
        shk_loc = (snx, sny)
        arr[snx][sny] = (0, 0)
        bak_arr = deepcopy(arr)
        fish()
        cur = shk(snx, sny, bak_fish[1]) + bak_fish[0]
        arr = deepcopy(bak_arr)
        shk_loc = bak_loc
        arr[snx][sny] = bak_fish
        ans = max(ans, cur)
    return ans

fish()
print(fscore + shk(0, 0, sf))
