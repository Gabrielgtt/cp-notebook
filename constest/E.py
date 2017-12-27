from math import factorial
n, k = map(int, raw_input().split())

res = 0

for num in xrange(k+1, n):
	aux = factorial(n-k) * factorial(k)

	for i in xrange(1, n-k-1):
		aux -= factorial(i) * factorial(n-i)
	res += aux

print res
	