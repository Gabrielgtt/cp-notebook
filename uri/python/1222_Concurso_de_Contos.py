from math import ceil

while True:
	try:
		num_pal, num_lin, num_car = [int(x) for x in raw_input().split()]
		conto = raw_input()
		pivot = 0
		leni = len(conto)
		linhas = 0.0

		while True:
			pivot += num_car
			if pivot < leni:
				while True:
					if pivot < 0 or conto[pivot] == " ":
						break
					pivot -= 1
				linhas += 1
			else:
				linhas += 1
				break
			pivot += 1

		print int(ceil(linhas/num_lin))

	except EOFError:
		break
