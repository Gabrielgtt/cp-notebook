frase = raw_input()
flag = 0
res = ""

for i in xrange(len(frase)):
	if frase[i] == ' ':
		res += " "
	elif flag:
		res += frase[i]
		flag = 0
	else:
		flag = 1

print res	