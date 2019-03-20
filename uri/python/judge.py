#coding: utf-8
# JUDGE DA PASTA URI-PYTHON
from itertools import izip
import filecmp
from os import system
from time import time

def run(comando):
	antes = time()
	system(comando)
	depois = time() 

	print "Execution time = {0:.5f}".format(depois - antes)

def comparar():
	saida = open("output", "r")
	correto = open("c_output", "r")

	if filecmp.cmp("output", "c_output"):
		print "Perfect!"
	else: 
		for i, linhas in enumerate(izip(saida.readlines(), correto.readlines())):
			if linhas[0] != linhas[1]:
				print "Erro encontrado na linha {0}".format(i+1)
				print repr(linhas[0]), repr(linhas[1])

run("python 2321_Detectando_colisoes.py<input >output")
comparar()