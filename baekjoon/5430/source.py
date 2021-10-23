import sys
from collections import deque
import re

input = sys.stdin.readline

t = int(input())
rg = re.compile('[0-9]+')

for _ in range(t):
    p = input()
    n = int(input())
    a = deque(rg.findall(input()))
    flg = 0
    rcnt = 0
    for c in p:
        if c == 'R':
            rcnt += 1
        if c == 'D':
            if a:
                if rcnt%2:
                    a.pop()
                else:
                    a.popleft()
            else:
                flg = 1
    if(rcnt%2): a.reverse()
    if(flg): print('error')
    else: print(str(list(a)).replace("'", "").replace(" ", ""))
