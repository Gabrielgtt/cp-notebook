#coding: utf-8
# JUDGE DA PASTA URI-CPP
from itertools import izip
import filecmp
from os import system
from time import time

def const_run(const, run):
	system(const)
	antes = time()
	system(run)
	depois = time() 

	print "Execution time = {0:.5f}".format(depois - antes)

def comparar():
	saida = open("output", "r")
	correto = open("c_output", "r")

	if filecmp.cmp("output", "c_output"):
		print "Perfect!"
	else:
		print "Erros:"
		total = 0
		cont = 0
		for i, linhas in enumerate(izip(saida.readlines(), correto.readlines())):
			total += 1
			if linhas[0] != linhas[1]:
				print "Linha {0:4} --".format(i+1),
				print "{0:15}{1:15}".format(repr(linhas[0]), repr(linhas[1]))
				cont += 1
		print "Qnt Errors = %d/%d" % (cont, total)

const_run("g++ coding.cpp -o coding",
		  "./coding <input >output")
comparar()