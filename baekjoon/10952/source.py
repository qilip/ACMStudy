import sys

input = sys.stdin.readlines

for c in input():
    x, y = map(int, c.split())
    if not x and not y: break
    print(x+y)
