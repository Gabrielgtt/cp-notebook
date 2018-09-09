#include <bits/stdc++.h>
#define MAXN 110
using namespace std;

int grafo[MAXN][MAXN], path[MAXN], vis[MAXN];
int nodes, source, sink, edges;

int findPath(){
	memset(vis, 0, sizeof vis);
	memset(path, -1, sizeof path);
	queue <int> fila;
	bool procurando = true;
	int atual;

	fila.push(source);
	while (!fila.empty() && procurando){
		atual = fila.front(); fila.pop();
		vis[atual] = 1;

		for (int prox=1; prox<=nodes; prox++){
			if (!vis[prox] && grafo[atual][prox] > 0){
				fila.push(prox);
				path[prox] = atual;
				if (prox == sink){
					procurando = false;
					break;
				}
			}
		}
	}

}

int maxFlow(){
	int max_flow = 0;
	int flowzinho;
	while (true){
		flowzinho = findPath();
		if (flowzinho == 0) break;
		else max_flow += flowzinho;
	}

	return max_flow;
}

int main(){

	int querry = 1;
	while (true){
		scanf("%d", &nodes);
		if (nodes == 0) break;

		printf("Network %d\n", querry++);

		scanf("%d %d %d", &source, &sink, &edges);
		
		memset(grafo, 0, sizeof grafo);
		int de, para, custo;
		for (int i=0; i<edges; i++){
			scanf("%d %d %d", &de, &para, &custo);
			grafo[de][para] = custo;
			grafo[para][de] = custo;
		}

		printf("The bandwidth is %d.\n\n", maxFlow());

	}

	return 0;
}