from itertools import izip
from os import system
from time import time

system("g++ A.cpp -o A")
system("g++ gerador.cpp -o gerador")

tempo_total = 1.0
while (tempo_total <= 1):
	system("./gerador >input")
	antes = time() 
	system("./A <input")
	depois = time()
	tempo_total = depois - antes
	print "Execution time = {0:.5f}".format(tempo_total) 


# saida = open("output", "r")
# correto = open("c_output", "r")
# compare = 0

# if compare:
# 	for i, linhas in enumerate(izip(saida.readlines(), correto.readlines())):
# 		if linhas[0] != linhas[1]:
# 			print "Erro encontrado na linha {0}".format(i+1)