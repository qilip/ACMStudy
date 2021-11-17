import sys

input = sys.stdin.readline

n = int(input())
nn = list(map(int, input().split()))

nn.sort(reverse=True)
ans = 0
for i in range(n):
    ans += nn[i] * (i+1)
print(ans)
