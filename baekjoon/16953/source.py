from collections import deque
a, b = map(int, input().split())
q = deque()
q.append((a, 0))
while q:
    x, c = q.popleft()
    if x == b:
        q.append((x, c))
        print(c+1)
        break
    if x * 10 + 1 <= b:
        q.append((x * 10 + 1, c + 1))
    if x * 2 <= b:
        q.append((x * 2, c + 1))
if not q:
    print(-1)
