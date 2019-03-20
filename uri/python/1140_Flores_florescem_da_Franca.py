frase = raw_input().split()

while True:
	if frase[0] == '*':
		break

	letra = frase[0][0].lower()

	for palavra in frase:
		if palavra[0].lower() != letra:
			print "N"
			break
	else:
		print "Y"

	frase = raw_input().split()