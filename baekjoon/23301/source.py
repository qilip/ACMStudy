import sys

input = sys.stdin.readline

n, t = map(int, input().split())
table = [0] * 2010

for _ in range(n):
    k = int(input())
    for _ in range(k):
        a, b = map(int, input().split())
        table[a:b] = [x + 1 for x in table[a:b]]

maxi = 0
maxs = 0

for i in range(1001):
    s = sum(table[i:i+t])
    if s > maxi:
        maxi = s
        maxs = i

print(maxs, maxs+t)
