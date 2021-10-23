import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n = int(input())
g = [list() for _ in range(n+1)]
data = [list(map(int, input().split())) for _ in range(n-1)]

for a, b, c in data:
    g[a].append((b, c))

res = 0
def dfs(cur):
    global res
    c_res = [0, 0]
    for nxt, cost in g[cur]:
        ncost = cost + dfs(nxt)
        c_res.append(ncost)
    c_res.sort(reverse=True)
    ch = c_res[0] + c_res[1]
    res = max(res, ch)
    res = max(res, c_res[0], c_res[1])
    return max(c_res[0], c_res[1])

dfs(1)

print(res)
