import sys

input = sys.stdin.readline

n, q = map(int, input().split())

back = []
front = []
cur = 0

for _ in range(q):
    w = input().split()
    if w[0] == 'B' and back:
        front.append(cur)
        cur = back.pop()
    if w[0] == 'F' and front:
        back.append(cur)
        cur = front.pop()
    if w[0] == 'A':
        i = int(w[1])
        front.clear()
        if cur:
            back.append(cur)
        cur = i
    if w[0] == 'C':
        for i in range(1, len(back)):
            if back[i] == back[i-1]:
                back[i-1] = -1
        back = [i for i in back if i != -1]

print(cur)
print(' '.join(map(str,back[::-1])) if back else -1)
print(' '.join(map(str,front[::-1])) if front else -1)
