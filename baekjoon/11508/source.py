import sys

input = sys.stdin.readline

n = int(input())
data = [int(input()) for _ in range(n)]

data.sort(reverse=True)
a = sum(data)
b = 0
if n > 2: b = sum(data[2::3])
print(a-b)
