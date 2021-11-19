import sys

input = sys.stdin.readline

s = input().strip()

score = 0
ans = 0

d = {'(':1, ')':-1, '{':2, '}':-2, '[':3, ']':-3}
for c in s:
    if c in d:
        score += d[c]
    else:
        ans = max(ans, score)

print(ans)
