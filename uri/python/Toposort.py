n = int(raw_input())
graph = [[]]

for i in xrange(1, n+1):
	filhos = map(int, raw_input().split())
	graph.append(filhos[:len(filhos)-1])

def topoSort(graph):
	flags = []
	toposorted = []

	def dfs(start, graph, flags, toposorted):
		flags.append(start)
		for prox in graph[start]:
			if prox not in flags:
				dfs(prox, graph, flags, toposorted)
		toposorted.insert(0, start)

	for vert in xrange(1, n+1):
		if vert not in flags:
			dfs(vert, graph, flags, toposorted)
	
	return toposorted

print " ".join(map(str, topoSort(graph)))