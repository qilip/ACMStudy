import sys
import decimal

input = sys.stdin.readline

a, b = map(decimal.Decimal, input().split())
c = decimal.Decimal(299792458)
print((a+b)/(1+(a*b/(c*c))))
