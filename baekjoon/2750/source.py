import sys

n = int(input())
input = sys.stdin.readlines
a = list(map(int, input()))
a.sort()
print(*a, sep='\n')
