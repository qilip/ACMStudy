import sys
from collections import deque

input = sys.stdin.readline

n = int(input())
m = int(input())
data = [list(map(int, input().split())) for _ in range(m)]
g = [list() for _ in range(n+1)]
for a, b in data:
    g[a].append(b)
    g[b].append(a)

q = deque([1])
visited = [0] * (n+1)
visited[1] = 1

while q:
    cur = q.popleft()
    for nxt in g[cur]:
        if not visited[nxt]:
            q.append(nxt)
            visited[nxt] = 1
print(sum(visited)-1)
