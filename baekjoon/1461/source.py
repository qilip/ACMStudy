import sys

input = sys.stdin.readline

n, m = map(int, input().split())
data = list(map(int, input().split()))
a = list(filter(lambda x: x>0, data))
b = list(map(abs, filter(lambda x: x<0, data)))
a.sort(reverse=True)
b.sort(reverse=True)
ans = 0

a.append(0)
b.append(0)

if a[0]>b[0]: a, b = b, a
for i in range(0, len(a), m):
    ans += a[i]
for i in range(m, len(b), m):
    ans += b[i]
ans *= 2
ans += b[0]

print(ans)
