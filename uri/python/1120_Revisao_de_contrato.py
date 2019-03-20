while (1):
	a, b = raw_input().split()
	if a == '0': break
	res = "".join(b.split(a))
	if "".join(res.split('0')) == '': res = '0'
	print int(res)