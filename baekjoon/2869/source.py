import math

a, b, v = map(int, input().split())
c = a-b
v -= a
print(math.ceil(v/c)+1)
