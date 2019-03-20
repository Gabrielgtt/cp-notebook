lista = ["N", "L", "S", "O"]
while True:
	num = int(raw_input())
	if num == 0: break
	com = raw_input()
	cons = 0
	for letra in com:
		if letra == "D":
			cons += 1
		else:
			cons -= 1
	print lista[cons%4]