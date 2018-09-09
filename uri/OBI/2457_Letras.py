letra = input()
frase = input().split()

resposta = len(frase)
divisor = 0
for palavra in frase:
	if letra in palavra:
		divisor += 1

print("%.1f" % (divisor * 100 / resposta));