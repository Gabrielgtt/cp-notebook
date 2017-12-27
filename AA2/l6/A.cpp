#include <bits/stdc++.h>
#define MAXN 5010
#define MAXE 60009
#define INF 1e9
using namespace std;

int level[MAXN], source = 1, sink, n, e, proximo[MAXN];
vector<int> grafo[MAXN];

struct edge {
	int dest, rev;
	long long int cap, flow;
} edges[MAXE];

queue <int> fila;
bool levelGraph(){
	memset(level, 0, sizeof level);
	fila.push(source);
	level[source] = 1;
	int atual, id, prox;
	edge curEdge;

	while (!fila.empty()){
		atual = fila.front(); fila.pop();

		for (int i=0; i<grafo[atual].size(); i++){	
			id = grafo[atual][i];
			curEdge = edges[id];

			if ((curEdge.cap > curEdge.flow && curEdge.cap > 0) && level[curEdge.dest] == 0){
				level[curEdge.dest] = level[atual] + 1;
				fila.push(curEdge.dest);
			}
		}
	}

	return level[sink] != 0;
}

long long int blockFlow(int node, long long int minFlow){
	if (node == sink) return minFlow;
	long long int curFlow, tempFlow;
	edge curEdge;
	for (; proximo[node] < grafo[node].size(); ++proximo[node]){
		curEdge = edges[grafo[node][proximo[node]]];
		
		if (level[curEdge.dest] == level[node]+1 && curEdge.cap > curEdge.flow){
			curFlow = min(minFlow, curEdge.cap - curEdge.flow);
			tempFlow = blockFlow(curEdge.dest, curFlow);

			if (tempFlow > 0){
				edges[grafo[node][proximo[node]]].flow += tempFlow;
				edges[curEdge.rev].flow -= tempFlow;
				return tempFlow;
			}
		}
	}

	return 0;
}

long long int dinic(){
	long long int res = 0, flow;
	while (levelGraph()){
		memset(proximo, 0, sizeof proximo);
		while (flow = blockFlow(source, INF))
			res += flow;
	}
	return res;
}

int ligado[MAXN][MAXN];
int main(){
	scanf("%d %d", &n, &e);
	sink = n;

	int de, para, custo, idd = 1;
	for (int i=0; i<e; i++){
		scanf("%d %d %d", &de, &para, &custo);

		if (de == para) continue;

		if (ligado[de][para] == 0 && ligado[para][de] == 0){
			ligado[de][para] = idd;
			ligado[para][de] = idd;
			edges[idd].dest = para;
			edges[idd].rev = idd+1;
			edges[idd].cap = custo;
			edges[idd].flow = 0;
			grafo[de].push_back(idd++);

			edges[idd].dest = de;
			edges[idd].rev = idd-1;
			edges[idd].cap = custo;
			edges[idd].flow = 0;
			grafo[para].push_back(idd++);			
		} else {
			edges[ligado[para][de]].cap += custo;
			edges[ligado[para][de]+1].cap += custo;
		}

	}

	cout << dinic() << endl;
	return 0;
}