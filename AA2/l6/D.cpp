#include <bits/stdc++.h>
#define MAXN 110
#define MAXE 10009
#define INF 1e9
using namespace std;

int level[MAXN], source = 0, sink, n, e, proximo[MAXN], idd;
int ligado[MAXN][MAXN];
vector<int> grafo[MAXN];

struct edge {
	int dest, rev;
	long long int cap, flow;
} edges[MAXE];
edge selfEdge[MAXN];

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
			// printf("aresta de %d para %d com cap %lld tem flow %lld\n", atual, curEdge.dest, curEdge.cap, curEdge.flow);

			if ((curEdge.cap > curEdge.flow) && (selfEdge[curEdge.dest].cap > selfEdge[curEdge.dest].flow) && (level[curEdge.dest] == 0)){
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

	// if (node != sink && node != source) {
		minFlow = min(minFlow, selfEdge[node].cap - selfEdge[node].flow);
		// printf(">>> %d\n", node);		
	// }

	// printf("minFlow no node %d é %lld \n", node, minFlow);
	for (; proximo[node] < grafo[node].size(); ++proximo[node]){
		curEdge = edges[grafo[node][proximo[node]]];
		
		if (level[curEdge.dest] == level[node]+1 && curEdge.cap > curEdge.flow){
			// printf("estou indo para %d\n", curEdge.dest);
			curFlow = min(minFlow, curEdge.cap - curEdge.flow);
			// printf("cur flow %lld\n", curFlow);
			tempFlow = blockFlow(curEdge.dest, curFlow);
			// printf("voltando da recursao para %d com o flow min = %lld\n", edges[grafo[node][proximo[node]]].dest, tempFlow);
			if (tempFlow > 0){
				edges[grafo[node][proximo[node]]].flow += tempFlow;
				edges[curEdge.rev].flow -= tempFlow;
				selfEdge[curEdge.dest].flow += tempFlow;
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

void makeEdge(int de, int para, int custo){
	if (de == para) return;

	// printf(" >> %d %d\n", de, para);
	
	// if (ligado[de][para] == 0){
		// ligado[de][para] = idd;
		// ligado[para][de] = idd+1;
		edges[idd].dest = para;
		edges[idd].rev = idd+1;
		edges[idd].cap = custo;
		edges[idd].flow = 0;
		grafo[de].push_back(idd++);

		edges[idd].dest = de;
		edges[idd].rev = idd-1;
		edges[idd].cap = 0;
		edges[idd].flow = 0;
		grafo[para].push_back(idd++);			
	// } else {
	// 	edges[ligado[de][para]].cap += custo;
	// 	printf("%d %d\n", de, para);
	// 	// edges[ligado[de][para]+1].cap += custo;
	// }	
}

int main(){
	int selfCap, sources, sinks, i;
	while (scanf("%d", &n) != EOF){
		memset(ligado, 0, sizeof ligado);

		for (i=0; i<=n+1; i++) grafo[i].clear();

		idd = 1;
		sink = n+1;

		selfEdge[0].cap = INF;
		selfEdge[0].flow = 0;
		selfEdge[sink].cap = INF;
		selfEdge[sink].flow = 0;
		for (i=1; i<=n; i++){
			scanf("%d", &selfCap);
			selfEdge[i].cap = selfCap;
			selfEdge[i].flow = 0;
		}

		scanf("%d", &e);

		int de, para, custo;
		for (i=0; i<e; i++){
			scanf("%d %d %d", &de, &para, &custo);
			makeEdge(de, para, custo);
		}

		scanf("%d %d", &sources, &sinks);
		for (i=0; i<sources; i++){
			scanf("%d", &para);
			makeEdge(source, para, INF);
		}

		for (i=0; i<sinks; i++){
			scanf("%d", &de);
			// printf("de %d para %d\n", de, sink);
			makeEdge(de, sink, INF);
		}

		cout << dinic() << endl;
	}
	return 0;
}