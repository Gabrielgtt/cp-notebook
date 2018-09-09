#include <bits/stdc++.h>
#define MAXN 10000
using namespace std;

int path[MAXN], vis[MAXN], peso[MAXN][MAXN], match[MAXN];
int source = 0, sink = 9999;
vector<int> grafo[MAXN];

int bfs(){
	queue <int> fila;
	int atual, prox, anterior;
	memset(vis, 0, sizeof vis);
	memset(path, -1, sizeof path);
	bool rodando = true;
	fila.push(source);
	while (rodando && !fila.empty()){
		atual = fila.front(); fila.pop();
		vis[atual] = 1;
		for (int i=0; i<grafo[atual].size(); i++){
			prox = grafo[atual][i];
			if (!vis[prox] && peso[atual][prox] > 0){
				fila.push(prox);
				// printf("prox = %d\n", prox);
				path[prox] = atual;
				if (prox == sink){
					rodando = false;
					break;
				}
			}
		}
	}

	int flow = 1e9;
	atual = sink;
	while (path[atual] != -1){
		anterior = path[atual];
		flow = min(flow, peso[anterior][atual]);
		atual = anterior;
		// printf("%d - ", atual);
	}
	// printf("\n");

	if (flow == 1e9) return 0;

	atual = sink;
	while (path[atual] != -1){
		anterior = path[atual];
		peso[anterior][atual] -= flow;
		peso[atual][anterior] += flow;
		atual = anterior;
	}

	return flow;
}

int trocaTroca(int node){
	if (vis[node]) return 0;
	vis[node] = 1;
	for (int i=0; i<grafo[node].size(); i++){
		if (match[grafo[node][i]] == -1 || trocaTroca(match[grafo[node][i]])){
			match[grafo[node][i]] = node;
			return 1;
		}
	}
	return 0;
}

int maxFlow(){
	int maxf = 0, flow;
	while (true){
		if (flow = bfs()) maxf += flow;
		else break;
	}
	return maxf;
}

int main(){
	int t, n, x, y, aux;
	scanf("%d", &t);


	while (t--){
		scanf("%d", &n);

		for (int i=0; i<n+240; i++) grafo[i].clear();
		// memset(peso, 0, sizeof peso);
		int contador = 0;
		aux = 241;

		for (int i=0; i<n; i++){
			scanf("%d %d", &x, &y);
			x += 1;
			y += 121;

			if (grafo[x].size() == 0) contador++;
			if (grafo[y].size() == 0) contador++;

			grafo[0].push_back(x);
			peso[0][x] = 1;
			peso[x][0] = 0;
			grafo[0].push_back(y);
			peso[0][y] = 1;
			peso[y][0] = 0;

			// printf("%d -> %d\n", x, aux);
			grafo[x].push_back(aux);
			grafo[aux].push_back(x);
			peso[x][aux] = 1;
			peso[aux][x] = 0;

			// printf("%d -> %d\n", y, aux);
			grafo[y].push_back(aux);
			grafo[aux].push_back(y);
			peso[y][aux] = 1;
			peso[aux][y] = 0;

			grafo[aux].push_back(sink);
			peso[aux][sink] = 1;
			peso[sink][aux] = 0;

			aux++;
		}

		int maxMatch = 0;
		memset(match, -1 , sizeof match);
		for (int i=1; i<=240; i++){
			memset(vis, 0 , sizeof vis);
			maxMatch += trocaTroca(i);
		}

		printf("%d\n", min(contador - maxMatch, n - maxMatch));
	}

}