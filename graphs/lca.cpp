#include <bits/stdc++.h>
using namespace std;

// IMPLEMENTAÇÃO DE LCA COM QUERY DE DISTANCIA
const int MAXN = 100000;
const int MAXLOG = 25;

typedef make_pair mp; 
typedef pair <int, int> ii; 
typedef long long ll; 

vector <ii> grafo[MAXN]; // mudar o grafo se não for de distância
int level[MAXN], parent[MAXN][MAXLOG], logs[MAXN], dist[MAXN][MAXLOG];

void buildLCA(){
	for (int l=1; l<MAXLOG; l++){
		for (int i=1; i<=n; i++){
			parent[i][l] = parent[parent[i][l-1]][l-1];
			dist[i][l] = dist[parent[i][l-1]][l-1] + dist[i][l-1];
		}
	}
}

void dfs(int node, int pai, int l){
	for (int i=0; i<grafo[node].size(); i++){
		int prox = grafo[node][i].first;
		if (prox != pai){
			level[prox] = l+1;
			parent[prox][0] = node;
			dist[prox][0] = grafo[node][i].second;
			dfs(prox, node, l+1);
		}
	}
}

ll qDist(int a, int b){
	if (level[a] > level[b]) swap(a, b);

	int diff = level[b] - level[a], pulo;
	ll res = 0;
	while (diff > 0){
		pulo = diff & (-diff);
		res += dist[b][logs[pulo]];
		b = parent[b][logs[pulo]];
		diff -= pulo;
	}

	if (b == a) return res;

	for (int i=MAXLOG-1; i>=0; i--){
		if (parent[a][i] != parent[b][i]){
			res += dist[a][i];
			res += dist[b][i];
			a = parent[a][i];
			b = parent[b][i];
		}
	}

	res += dist[a][0];
	res += dist[b][0];
	return res;
}

int main(){
	int t;
	scanf("%d", &t);

	// preencher os logs
	logs[0] = 0;
	logs[1] = 0;
	for (int i=2; i<MAXN; i++){
		logs[i] = logs[i>>1] + 1;
	}

	level[1] = 1;
	dfs(1, 1);
	buildLCA();
	return 0;
}