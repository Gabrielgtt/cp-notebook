from collections import deque

def bfs(graph, queue, goal, visited):
	aux = deque()
	
	while queue:
		vertex = queue.popleft()
		if vertex == goal:
			return 1
		if vertex not in visited:
		    visited.add(vertex)
		    aux.extend(graph[vertex]-visited)

	return bfs(graph, aux, goal, visited) + 1

while True:
	try:
		grafo = {'h8': set(['g6', 'f7']), 'f1': set(['h2', 'g3', 'd2', 'e3']), 'f2': set(['g4', 'h3', 'h1', 'e4', 'd3', 'd1']), 'f3': set(['g5', 'g1', 'h2', 'e1', 'h4', 'e5', 'd4', 'd2']), 'f4': set(['g6', 'e6', 'g2', 'h3', 'h5', 'd5', 'd3', 'e2']), 'f5': set(['g7', 'g3', 'h6', 'h4', 'd6', 'd4', 'e7', 'e3']), 'f6': set(['g4', 'g8', 'h7', 'h5', 'e8', 'e4', 'd7', 'd5']), 'f7': set(['h8', 'h6', 'g5', 'e5', 'd8', 'd6']), 'h2': set(['f1', 'g4', 'f3']), 'h3': set(['f2', 'f4', 'g5', 'g1']), 'h1': set(['f2', 'g3']), 'h6': set(['g4', 'g8', 'f5', 'f7']), 'h7': set(['f8', 'g5', 'f6']), 'h4': set(['g6', 'f3', 'f5', 'g2']), 'h5': set(['g7', 'g3', 'f4', 'f6']), 'b4': set(['d3', 'a2', 'a6', 'c2', 'd5', 'c6']), 'b5': set(['c3', 'a3', 'a7', 'd6', 'd4', 'c7']), 'b6': set(['c8', 'a4', 'a8', 'd7', 'd5', 'c4']), 'b7': set(['d6', 'a5', 'c5', 'd8']), 'b1': set(['c3', 'a3', 'd2']), 'b2': set(['a4', 'c4', 'd3', 'd1']), 'b3': set(['a1', 'a5', 'd4', 'd2', 'c1', 'c5']), 'd6': set(['f5', 'f7', 'c8', 'b5', 'b7', 'e8', 'e4', 'c4']), 'd7': set(['f6', 'f8', 'b6', 'e5', 'b8', 'c5']), 'd4': set(['f3', 'f5', 'b5', 'b3', 'c2', 'e6', 'c6', 'e2']), 'd5': set(['f4', 'f6', 'b4', 'b6', 'c3', 'e7', 'c7', 'e3']), 'd2': set(['f1', 'f3', 'b1', 'b3', 'e4', 'c4']), 'd3': set(['f2', 'f4', 'b4', 'b2', 'e5', 'c1', 'e1', 'c5']), 'd1': set(['c3', 'f2', 'e3', 'b2']), 'c7': set(['e6', 'b5', 'e8', 'a6', 'a8', 'd5']), 'e5': set(['g6', 'g4', 'f7', 'd3', 'f3', 'd7', 'c6', 'c4']), 'b8': set(['d7', 'c6', 'a6']), 'f8': set(['d7', 'e6', 'h7', 'g6']), 'c5': set(['b3', 'b7', 'd7', 'a4', 'a6', 'e4', 'e6', 'd3']), 'd8': set(['b7', 'c6', 'e6', 'f7']), 'c4': set(['b6', 'd6', 'a3', 'a5', 'b2', 'e5', 'd2', 'e3']), 'g7': set(['f5', 'e6', 'e8', 'h5']), 'g6': set(['h8', 'f4', 'f8', 'h4', 'e5', 'e7']), 'g5': set(['f3', 'f7', 'h3', 'h7', 'e4', 'e6']), 'g4': set(['f2', 'f6', 'h2', 'h6', 'e5', 'e3']), 'g3': set(['f1', 'f5', 'h1', 'h5', 'e4', 'e2']), 'g2': set(['f4', 'e1', 'h4', 'e3']), 'g1': set(['h3', 'f3', 'e2']), 'e4': set(['g5', 'g3', 'f6', 'f2', 'd6', 'c3', 'd2', 'c5']), 'g8': set(['e7', 'h6', 'f6']), 'a1': set(['c2', 'b3']), 'a3': set(['b5', 'c2', 'b1', 'c4']), 'a2': set(['c3', 'b4', 'c1']), 'a5': set(['b3', 'b7', 'c6', 'c4']), 'a4': set(['c3', 'b6', 'b2', 'c5']), 'a7': set(['b5', 'c8', 'c6']), 'a6': set(['b4', 'b8', 'c7', 'c5']), 'c3': set(['d5', 'b1', 'b5', 'a2', 'a4', 'e4', 'e2', 'd1']), 'c2': set(['b4', 'a1', 'a3', 'd4', 'e1', 'e3']), 'c1': set(['a2', 'b3', 'd3', 'e2']), 'e6': set(['g7', 'g5', 'f4', 'f8', 'd8', 'd4', 'c7', 'c5']), 'e1': set(['c2', 'f3', 'g2', 'd3']), 'c6': set(['d8', 'b4', 'a5', 'a7', 'e5', 'e7', 'b8', 'd4']), 'e3': set(['f1', 'g4', 'g2', 'd1', 'f5', 'c2', 'd5', 'c4']), 'e2': set(['f4', 'g1', 'c3', 'g3', 'c1', 'd4']), 'e7': set(['g6', 'f5', 'g8', 'c8', 'd5', 'c6']), 'a8': set(['b6', 'c7']), 'c8': set(['d6', 'e7', 'b6', 'a7']), 'e8': set(['g7', 'd6', 'c7', 'f6'])}
		beg, end = raw_input().split()
		visited = set()
		print "To get from {0} to {1} takes {2} knight moves.".format(beg, end, bfs(grafo, deque([beg]), end, visited)-1)
	except EOFError:
		break