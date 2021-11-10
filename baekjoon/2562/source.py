import sys
n = list(map(int, sys.stdin.readlines()))
print(max(n))
print(n.index(max(n))+1)