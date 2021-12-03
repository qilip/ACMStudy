import sys

n = int(input())
input = sys.stdin.readlines
a = list(map(int, input()))
a.sort(reverse=True)
print(*a, sep='\n')
