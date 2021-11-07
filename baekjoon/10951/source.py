import sys

input = sys.stdin.readlines

data = [list(map(int, c.split())) for c in input()]
[print(x+y) for x, y in data]
