import sys

input = sys.stdin.readline

s = list(str(input().rstrip()))
s.sort(reverse=True)
print(*s, sep='')
