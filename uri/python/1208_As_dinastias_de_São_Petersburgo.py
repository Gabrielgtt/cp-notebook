def dfs(grafo, start, flagged):
	if grafo[start]:
		for other in grafo[start]:
			if other not in flagged:
				flagged.append(other)
				return dfs(grafo, other, flagged)
	return 1

while True:
	try:
		m, n = raw_input().split()
		tree = {}
		
		for person in range(int(m)):
			tree[str(person+1)] = []
		
		for conection in range(int(n)):
			father, son = raw_input().split()
			tree[father].append(son)
		
		flagged = []
		res = 0

		for key in tree:
			if key not in flagged:
				res += dfs(tree, key, flagged)

		print res
	
	except EOFError:
		break