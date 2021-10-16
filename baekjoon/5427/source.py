import sys
from collections import deque

input = sys.stdin.readline

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
w = h = 0

def init(g, st):
	q = deque()
	q.append((0, *st))
	while q:
		cost, cx, cy = q.popleft()
		for i in range(4):
			nx, ny = cx + dx[i], cy + dy[i]
			if not (0 <= nx < h and 0 <= ny < w): continue
			ncost = cost + 1
			if g[nx][ny] > ncost:
				g[nx][ny] = ncost
				q.append((ncost, nx, ny))

def bfs(g, st):
	q = deque()
	q.append((0, *st))
	visited = [[0] * w for _ in range(h)]
	visited[st[0]][st[1]] = 1
	while q:
		cost, cx, cy = q.popleft()
		if cx == 0 or cy == 0 or cx == h-1 or cy == w-1: return cost + 1
		for i in range(4):
			nx, ny = cx + dx[i], cy + dy[i]
			if not (0 <= nx < h and 0 <= ny < w): continue
			ncost = cost + 1
			if g[nx][ny] > ncost and not visited[nx][ny]:
				visited[nx][ny] = 1
				q.append((ncost, nx, ny))
	return 'IMPOSSIBLE'

t = int(input())
for _ in range(t):
	w, h = map(int, input().split())
	data = [list(input().rstrip()) for _ in range(h)]
	g = [[0] * w for _ in range(h)]
	sg = -1
	fire = []
	for i in range(h):
		for j in range(w):
			if data[i][j] == '@':
				sg = (i, j)
				g[i][j] = 99999999
			if data[i][j] == '*':
				fire.append((i, j))
			if data[i][j] == '.':
				g[i][j] = 99999999
	for i, j in fire:
		init(g, (i, j))
	print(bfs(g, sg))
