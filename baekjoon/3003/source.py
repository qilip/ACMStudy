a = list(map(int, input().split()))
for q, p in zip([1, 1, 2, 2, 2, 8], a):
    print(q-p, end=' ')