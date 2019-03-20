from math import factorial

for i in xrange(int(raw_input())):
	marbs, colors = map(int, raw_input().split())
	marbs -= 1
	colors -= 1
	res = 0  	
	faltam = marbs-colors
	res += factorial(marbs)/(factorial(abs(marbs-colors))*factorial(colors)) 

	print res