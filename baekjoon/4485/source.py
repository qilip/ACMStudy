import sys
import heapq
hqp = heapq.heappush
hqo = heapq.heappop

input = sys.stdin.readline

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def dijk(g):
	q = []
	visited = [[0] * n for _ in range(n)]
	hqp(q, (g[0][0], 0, 0))
	dist = [[int(1e9)] * n for _ in range(n)]
	dist[0][0] = g[0][0]
	while q:
		cost, cx, cy = hqo(q)
		for i in range(4):
			nx, ny = cx + dx[i], cy + dy[i]
			if not (0 <= nx < n and 0 <= ny < n): continue
			ncost = cost + g[nx][ny]
			if dist[nx][ny] > ncost and not visited[nx][ny]:
				visited[nx][ny] = 1
				dist[nx][ny] = ncost
				hqp(q, (ncost, nx, ny))
	return dist[n-1][n-1]

t = 1
while True:
	n = int(input())
	if not n: break
	g = [list(map(int, input().split())) for _ in range(n)]
	print('Problem ', t, ': ', dijk(g), sep='')
	t += 1
