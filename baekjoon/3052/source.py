d = []
for _ in range(10):
    a = int(input())
    if a%42 not in d:
        d.append(a%42)
print(len(d))