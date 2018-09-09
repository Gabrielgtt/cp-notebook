#include <bits/stdc++.h>
#define MAXN 10300
using namespace std;

int path[MAXN], match[MAXN], vis[MAXN], peso[MAXN][MAXN];
int source = 0, sink = 10299;
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
	int t, n, x, y, aux;
	scanf("%d", &t);


	while (t--){
		scanf("%d", &n);

		for (int i=0; i<n+245; i++) grafo[i].clear();
		// memset(peso, 0, sizeof peso);
		int contador = 0;
		set <int> cont;
		aux = 241;

		for (int i=0; i<n; i++){
			scanf("%d %d", &x, &y);
			x += 1;
			y += 121;

			cont.insert(x);
			cont.insert(y);
			// if (grafo[x].size() == 0) contador++;
			// if (grafo[y].size() == 0) contador++;

			grafo[x].push_back(aux);
			grafo[y].push_back(aux);
			aux++;
		}


		int maxMatch = 0;
		memset(match, -1 , sizeof match);
		for (int i=1; i<=240; i++){
			memset(vis, 0 , sizeof vis);
			maxMatch += trocaTroca(i);
		}

		printf("%d\n", max(((int)cont.size()), n) - maxMatch);
	}

}