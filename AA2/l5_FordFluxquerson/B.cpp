#include <bits/stdc++.h>
#define MAXN 400
#define INF 1e9
using namespace std;

int source = 'A', sink = 'Z', path[MAXN], peso[MAXN][MAXN], vis[MAXN];
vector <int> grafo[MAXN];

int findPath(){
	queue <int> fila;
	fila.push(source);
	bool procurando = true;
	int atual, prox;

	memset(vis, 0, sizeof vis);
	memset(path, -1, sizeof path);

	while (!fila.empty() && procurando){
		atual = fila.front(); fila.pop();
		vis[atual] = 1;
		// printf("atual = %c\n", atual);

		for (int i=0; i<grafo[atual].size(); i++){
			prox = grafo[atual][i];
			// printf("prox = %c\n", prox);
			if (!vis[prox] && peso[atual][prox] > 0){
				path[prox] = atual;
				fila.push(prox);

				if (prox == sink){
					procurando = false;
					break;
				}
			}
		}
	}

	int flow = INF, anterior;
	atual = sink;

	while (path[atual] != -1){
		anterior = path[atual];
		flow = min(flow, peso[anterior][atual]);
		atual = anterior;
	}

	if (flow == INF) return 0;

	atual = sink;
	while (path[atual] != -1){
		anterior = path[atual];
		peso[anterior][atual] -= flow;
		peso[atual][anterior] += flow;
		atual = anterior;
	}

	return flow;
}

int maxFlow(){
	int resultado = 0, aux;

	while (true){
		aux = findPath();
		if (aux == 0) break;
		resultado += aux;
	}

	return resultado;
}

int main(){
	int n, p;
	char c1, c2;
	scanf("%d", &n);
	getchar();

	for (int i=0; i<n; i++){
		scanf("%c %c %d", &c1, &c2, &p);
		getchar();

		// printf("%c %c %d\n", c1, c2, p);

		grafo[c1].push_back(c2);
		grafo[c2].push_back(c1);

		peso[c1][c2] += p;
	}

	printf("%d\n", maxFlow());

	return 0;
}