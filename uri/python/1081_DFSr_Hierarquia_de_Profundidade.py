def dfs(graph, start, flags, espaco = "  "):
	flags.add(start)
	for prox in sorted(graph[start]):
		if prox in flags:
			print "%s%s-%s" % (espaco, start, prox)
		else:
			flags.add(prox)
			print "%s%s-%s pathR(G,%s)" % (espaco, start, prox, prox)
			if prox in graph:
				dfs(graph, prox, flags, espaco + "  ")

for n in range(int(raw_input())):
	v, e = [int(x) for x in raw_input().split()]
	mapa = {}
	flaggeds = set()

	for edge in range(e):
		v1, v2 = raw_input().split()
		if v1 not in mapa:
			mapa[v1] = set()
		mapa[v1].add(v2)

	print "Caso %d:" % (n+1)
	for key in sorted(mapa):
		if str(key) not in flaggeds:
			dfs(mapa, str(key), flaggeds)
			print ""