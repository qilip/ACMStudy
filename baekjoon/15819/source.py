import sys
from collections import deque

input = sys.stdin.readline

n, m = map(int, input().split())
data = [input().split() for _ in range(n)]
data.sort()

print(*data[m-1])
