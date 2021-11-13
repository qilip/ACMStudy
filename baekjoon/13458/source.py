import sys

input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))
b, c = map(int, input().split())

ans = 0
for i in a:
    ans += 1
    i -= b
    if i<=0: continue
    ans += i//c
    if i%c: ans += 1
print(ans)
