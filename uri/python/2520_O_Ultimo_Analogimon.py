while 1:
	try:
		lin, col = [int(x) for x in raw_input().split()]

		posEu = [0, 0]
		posMon = [0, 0]

		flag = 0

		for i in range(lin):

			linha = raw_input().split()

			if flag < 2:
				for j in range(col):
					if linha[j] == "2":
						posMon = [i, j]
						flag += 1

					if linha[j] == "1":
						posEu = [i, j]
						flag += 1


		dist = [abs(posMon[0] - posEu[0]), abs(posMon[1] - posEu[1])]

		resposta = 0
		while dist != [0, 0]:
			if dist[0] > dist[1]:
				dist[0] -= 1
			else:
				dist[1] -= 1
			resposta += 1

		print resposta
	except EOFError:
		break