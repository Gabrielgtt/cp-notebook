from math import factorial
x = int(raw_input())

res = 0
for i in xrange(1, x+1):
	res += 2**i

print res