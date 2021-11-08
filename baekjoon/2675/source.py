import sys

input = sys.stdin.readline

t = int(input())

for _ in range(t):
    r,s = input().split()
    r = int(r)
    ans = map(lambda x: x * r, s)
    print(*ans, sep='')
