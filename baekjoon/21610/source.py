import sys

input = sys.stdin.readline

n, m = map(int, input().split())
bucket = [list(map(int, input().split())) for _ in range(n)]
mov = [list(map(int, input().split())) for _ in range(m)]
cloud = [[0] * n for _ in range(n)]
cloud[n-1][0] = cloud[n-1][1] = cloud[n-2][0] = cloud[n-2][1] = 1
dirc = [(0, 0), (0, -1), (-1, -1), (-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1)]

def rain(x, y):
    bucket[x][y] += 1
    cloud[x][y] = -1

def move(d, s):
    x, y = dirc[d]
    nxt = []
    for i in range(n):
        for j in range(n):
            if cloud[i][j] == 1:
                cloud[i][j] = 0
                nxt.append(((i+s*x+n)%n, (j+s*y+n)%n))
    for i, j in nxt:
        rain(i, j)
    for i, j in nxt:
        for dx, dy in [(-1, -1), (-1, 1), (1, -1), (1, 1)]:
            if 0 <= i + dx < n and 0 <= j + dy < n and bucket[i + dx][j + dy]:
                bucket[i][j] += 1

def creud():
    for i in range(n):
        for j in range(n):
            if cloud[i][j] == -1: cloud[i][j] = 0
            elif bucket[i][j]>1:
                cloud[i][j] = 1
                bucket[i][j] -= 2

for d, s in mov:
    move(d, s)
    creud()

print(sum(map(sum, bucket)))
