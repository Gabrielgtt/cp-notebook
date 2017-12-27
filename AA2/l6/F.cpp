#include <bits/stdc++.h>
#define MAXN 220
using namespace std;

int testes, qtd1, qtd2, arr[MAXN], match[MAXN], vis[MAXN];
vector<int> grafo[MAXN];

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

int main(){
	scanf("%d", &testes);
	int aux;
	for (int t = 1; t <= testes; t++){
		scanf("%d", &qtd1);
		for (int i=1; i<=qtd1; i++){
			scanf("%d", &arr[i]);
		}	

		scanf("%d", &qtd2);
		for (int i=0; i<=qtd1+qtd2; i++) grafo[i].clear();

		for (int i=qtd1+1; i<=qtd1+qtd2; i++){
			scanf("%d", &aux);

			for (int j=1; j<=qtd1; j++){
				if (arr[j] != 0 && aux % arr[j] == 0){
					// printf("aresta de %d para %d\n", arr[j], aux);
					grafo[j].push_back(i);
					// grafo[aux].push_back(arr[j]);
				}
				if (arr[j] == aux && aux == 0){
					grafo[j].push_back(i);
				}
			}
		}

		int maxMatch = 0;
		memset(match, -1 , sizeof match);
		for (int i=1; i<=qtd1; i++){
			memset(vis, 0 , sizeof vis);
			maxMatch += trocaTroca(i);
		}

		printf("Case %d: %d\n", t, maxMatch);
	}


	return 0;
}