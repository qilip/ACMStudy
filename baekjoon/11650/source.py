import sys

input = sys.stdin.readline

n = int(input())
data = [list(map(int, input().split())) for _ in range(n)]

data.sort()

for i in data:
    print(i[0], i[1])
