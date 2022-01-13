a, b = map(int, input().split())
c = list(map(lambda x: x-a*b ,map(int, input().split())))
print(*c)
