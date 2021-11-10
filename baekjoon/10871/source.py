n, x = map(int, input().split())
nums = list(map(int, input().split()))
print(*list(filter(lambda k: k < x, nums)))