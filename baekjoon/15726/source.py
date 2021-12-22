import math
a, b, c = map(int, input().split())
print(math.floor(max(a/b*c, a*b/c)))