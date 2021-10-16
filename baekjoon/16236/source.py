import sys
import heapq

hp = heapq
hpp = hp.heappush
hpo = hp.heappop

input = sys.stdin.readline
n = int(input())
data = [list(map(int, input().split())) for _ in range(n)]

dx = [-1, 0, 0, 1]
dy = [0, -1, 1, 0]

def search(num):
	for x in range(n):
		for y in range(n):
			if data[x][y] == num: return x, y

def bfs(start, size):
	q = []
	hpp(q, (0, *start))
	visited = [[0] * n for _ in range(n)]
	visited[start[0]][start[1]] = 1
	while q:
		cost, cx, cy = hpo(q)
		if 0 < data[cx][cy] < size: return cx, cy, cost
		for i in range(4):
			nx, ny, nc = cx + dx[i], cy + dy[i], cost+1
			if not (0 <= nx < n and 0 <= ny < n): continue
			if not (visited[nx][ny] or data[nx][ny] > size):
				visited[nx][ny] = 1
				hpp(q, (nc, nx, ny))
	return -1, -1, -1

shk = 2
shk_cnt = 0
cur = search(9)
data[cur[0]][cur[1]] = 0
ans = 0

while True:
	nxt = bfs(cur, shk)
	if nxt[0] == -1: break
	sx, sy, sc = nxt
	data[sx][sy] = 0
	cur = sx, sy
	shk_cnt += 1
	if shk_cnt == shk:
		shk_cnt = 0
		shk += 1
	ans += sc

print(ans)
