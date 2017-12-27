from collections import defaultdict
from heapq import *
import itertools

def constant_factory(value):
	return itertools.repeat(value).next

edges = [("0", "1", 1), ("0", "4", 1),
		 ("1", "0", 1), ("1", "2", 1),
		 ("1", "5", 1), ("2", "1", 1),
		 ("2", "3", 1), ("2", "6", 1),
		 ("3", "2", 1), ("3", "7", 1), 
		 ("4", "0", 1), ("4", "8", 1),
		 ("5", "1", 1), ("5", "6", 1),
		 ("5", "10", 1), ("6", "2", 1),
		 ("6", "5", 1), ("6", "11", 1),
		 ("7", "3", 1), ("7", "11", 1),
		 ("8", "4", 1), ("8", "9", 1),
		 ("9", "8", 1), ("9", "10", 1),
		 ("10", "5", 1), ("10", "9", 1),
		 ("10", "11", 1), ("11", "6", 1),
		 ("11", "10", 1), ("11", "12", 1),
		 ("12", "7", 1), ("12", "11", 1)]

def dijkstra(edges, start):
	grafo = defaultdict(dict)
	path = [(0, start)] #Priority Queue
	d = defaultdict(constant_factory(float("inf")))
	d[start] = 0
	
	for de, para, dist in edges:
		grafo[de][para] = dist

	while path:
		dist, vert = heappop(path)
		for prox in grafo[vert]:
			caminho = dist + grafo[vert][prox]
			if caminho < d[prox]: 
				d[prox] = caminho
				heappush(path, (caminho, prox))

	print d

dijkstra(edges, "0")
