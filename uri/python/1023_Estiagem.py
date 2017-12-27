from math import *
from collections import Counter

vez = 1;
cidade = Counter();

def cout(i):
	if cidade[i]:
		print "%d-%d" % (cidade[i], i+1),
		cidade[i] = 0;

while True:
	#pegar valores	
	imoveis = int(raw_input());
	if not imoveis: break;
	consumo = 0;
	pessoas = 0;
	maior = 0;

	for i in xrange(imoveis):
		a, b = map(int, raw_input().split());
		consumo += b;
		pessoas += a;
		b /= a;
		if b > maior: maior = b;
		cidade[b-1] += a;

	#print
	if vez != 1: print
	print "Cidade# %d:" %vez;

	map(cout, xrange(maior))
	print

	#truncar
	value = int(consumo*100.0/pessoas);
	print "Consumo medio: %0.2f m3." % (value/100.0);
	vez += 1;