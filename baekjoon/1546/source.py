import sys

input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))
m = max(a)
b = list(map(lambda x: x/m*100, a))
print(sum(b)/n)
