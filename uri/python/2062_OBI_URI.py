i = raw_input()

palavras = raw_input().split()

for i, pal in enumerate(palavras):
	if len(pal) == 3:
		if (pal[0] == "O" and pal[1] == "B"):
			palavras[i] = "OBI"
		elif (pal[0] == "U" and pal[1] == "R"):
			palavras[i] = "URI"

print " ".join(palavras)
		