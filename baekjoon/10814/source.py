import sys

input = sys.stdin.readline

n = int(input())
data = [list(input().split()) for _ in range(n)]

data.sort(key=lambda x: int(x[0]))

for i in data:
    print(*i, sep=" ")
