#include <bits/stdc++.h>
#define MAXN 10002
using namespace std;

int source = 0, sink = 10001, peso[MAXN][MAXN], path[MAXN], vis[MAXN];
pair <int, int> numeros[MAXN];
map <int, long long int> indexVolta;
vector<int> grafo[MAXN];

int bfs(){
	queue <long long int> fila;
	fila.push(source);
	bool rodando = true;
	int atual, anterior, prox, flow = 1e9;

	memset(vis, 0, sizeof vis);
	memset(path, -1, sizeof path);
	while (rodando && !fila.empty()){
		atual = fila.front(); fila.pop();
		vis[atual] = 1;
		for (int i=0; i<grafo[atual].size(); i++){
			prox = grafo[atual][i];
			if (peso[atual][prox] > 0 && !vis[prox]){
				fila.push(prox);
				path[prox] = atual;
				if (prox == sink) {
					rodando = false;
					break;
				}
			}
		}
	}

	atual = sink;
	while (path[atual] != -1){
		// printf("%d - ", atual);
		anterior = path[atual];
		flow = min(flow, peso[anterior][atual]);
		atual = anterior;
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

int fordzao(){
	int maxFlow = 0, flow;
	while (true){
		if (flow = bfs()) maxFlow += flow;
		else break;
	}
	return maxFlow;
}

void getCaminhos(int n){
	long long int num;
	for (int i=1; i<=n; i++){
		if (peso[i][grafo[i][0]] == 0){
			num = indexVolta[grafo[i][0]];
			printf("%d * %d = %lld\n", numeros[i].first, numeros[i].second, num);
		} else if (peso[i][grafo[i][1]] == 0){
			num = indexVolta[grafo[i][1]];
			printf("%d - %d = %lld\n", numeros[i].first, numeros[i].second, num);
		} else if (peso[i][grafo[i][2]] == 0){
			num = indexVolta[grafo[i][2]];
			printf("%d + %d = %lld\n", numeros[i].first, numeros[i].second, num);
		}
	}
}

int main(){
	int n, num1, num2;
	map <long long int, int> index;
	scanf("%d", &n);

	int aux = n+1, iAtual;;
	for (int i=1; i<=n; i++){
		scanf("%d %d", &num1, &num2);
		numeros[i] = make_pair(num1, num2);

		grafo[0].push_back(i);
		peso[0][i] = 1;

		long long int operacao = (long long) num1 * (long long) num2;
		if (index.find(operacao) == index.end()){
			// printf("index %d para %lld\n", aux, operacao);
			index[operacao] = aux;
			indexVolta[aux] = operacao;
			aux++;
		}
		iAtual = index[operacao];

		grafo[i].push_back(iAtual);
		grafo[iAtual].push_back(i);
		grafo[iAtual].push_back(sink);
		peso[i][iAtual] = 1;
		peso[iAtual][sink] = 1;

		operacao = num1-num2;
		if (index.find(operacao) == index.end()){
			// printf("index %d para %lld\n", aux, operacao);
			index[operacao] = aux;
			indexVolta[aux] = operacao;
			aux++;
		}
		iAtual = index[operacao];

		grafo[i].push_back(iAtual);
		grafo[iAtual].push_back(i);
		grafo[iAtual].push_back(sink);
		peso[i][iAtual] = 1;
		peso[iAtual][sink] = 1;

		operacao = num1+num2;
		if (index.find(operacao) == index.end()){
			// printf("index %d para %lld\n", aux, operacao);
			index[operacao] = aux;
			indexVolta[aux] = operacao;
			aux++;
		}
		iAtual = index[operacao];

		grafo[i].push_back(iAtual);
		grafo[iAtual].push_back(i);
		grafo[iAtual].push_back(sink);
		peso[i][iAtual] = 1;
		peso[iAtual][sink] = 1;
	}

	int maxFlow = fordzao();

	if (maxFlow < n){
		printf("impossible\n");
	} else {
		getCaminhos(n);
	}	

	return 0;
}
