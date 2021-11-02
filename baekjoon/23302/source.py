import sys

input = sys.stdin.readline

r,c = map(int,input().split())
data = [list(input().split()) for _ in range(r)]

g = [[] for _ in range(r*c+1)]

def parse(s):
    a = 0
    b = 0
    for i in range(len(s)):
        if 'A' <= s[i] <= 'Z':
            a *= 26
            a += ord(s[i]) - ord('A') + 1
        else:
            b *= 10
            b += ord(s[i]) - ord('0')
    return a + (b - 1) * c

def stringify(n):
    b = (n-1) // c + 1
    a = (n-1) % c + 1
    res = ''
    while b:
        res += chr(ord('0') + b % 10)
        b //= 10
    while a:
        res += chr(ord('A') + (a-1) % 26)
        a = (a-1) // 26
    return res[::-1]

for i in range(r):
    for j in range(c):
        a = data[i][j].split('+')
        for k in range(len(a)):
            if a[k] == '.': continue
            g[parse(a[k])].append(i * c + j + 1)

num = [0] * (r*c+1)
fin = [0] * (r*c+1)
cnt = 0
s = []
ans = False

def scc(cur):
    global num, fin, cnt, s, ans
    cnt += 1
    num[cur] = cnt
    s.append(cur)
    res = num[cur]
    for nxt in g[cur]:
        if not num[nxt]:
            res = min(res, scc(nxt))
        elif not fin[nxt]:
            res = min(res, num[nxt])
    if res == num[cur]:
        cc = []
        while True:
            c = s.pop()
            fin[c] = 1
            cc.append(c)
            if c == cur: break
        if len(cc) > 1:
            ans = True
    return res

for i in range(1, r*c+1):
    if not ans:
        scc(i)

print('yes' if ans else 'no')
