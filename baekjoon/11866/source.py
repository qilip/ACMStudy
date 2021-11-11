from collections import deque
n, k = map(int, input().split())
q = deque(list(range(1, n+1)))
ans = []
while q:
    for _ in range(k-1):
        q.append(q.popleft())
    ans.append(q.popleft())
print('<', str(ans).strip('[]'), '>', sep='')
