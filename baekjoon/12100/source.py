import sys
from copy import deepcopy

input = sys.stdin.readline

n = int(input())
g = [list(map(int, input().split())) for _ in range(n)]
ans = 0

def push(dir):
    # 0 = left, 1 = up, 2 = right, 3 = down
    global g
    for _ in range(dir):
        g = [list(l[::-1]) for l in zip(*g[::-1])][::-1]
    for c in g:
        nc = list(filter(lambda x: x!=0, c))
        for i in range(1, len(nc)):
            if nc[i] == nc[i-1]:
                nc[i] = 0
                nc[i-1] *= 2
        nc = list(filter(lambda x: x!=0, nc))
        c[:] = list(nc) + [0]*(len(c)-len(nc))
    for _ in range(4-dir):
        g = [list(l[::-1]) for l in zip(*g[::-1])][::-1]

def run(cur):
    global ans, g
    if(cur==5):
        ans = max(ans, max(map(max, g)))
    else:
        for i in range(4):
            back = deepcopy(g)
            push(i)
            run(cur+1)
            g = deepcopy(back)

run(0)
print(ans)
