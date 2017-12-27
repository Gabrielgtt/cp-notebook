for i in xrange(1, int(raw_input())+1):
	print "Case %d:" % i

	num, base = raw_input().split()

	if base == "bin":
		print int(num, 2), "dec"
		print hex(int(num, 2))[2:], "hex"
	if base == "dec":
		print hex(int(num)).split('x')[-1], "hex"
		print bin(int(num)).split('b')[-1], "bin"
	if base == "hex":
		print int(num, 16), "dec"
		print bin(int(num, 16))[2:], "bin"

	print ""