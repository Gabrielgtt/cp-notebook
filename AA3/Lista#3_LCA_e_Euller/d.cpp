#include <bits/stdc++.h>
#define MAXN 100010
#define MAXLOG 22
#define ll long long
#define ii pair <int, int>
using namespace std;

vector <ii> grafo[MAXN];
int maxi[MAXN][MAXLOG], mini[MAXN][MAXLOG], level[MAXN], n, parent[MAXN][MAXLOG];
bool vis[MAXN];
void dfs(int node, int l){
	vis[node] = 1;
	for (int i=0; i<grafo[node].size(); i++){
		int prox = grafo[node][i].first;
		if (!vis[prox]){
			level[prox] = l+1;
			mini[prox][0] = grafo[node][i].second;
			maxi[prox][0] = grafo[node][i].second;
			parent[prox][0] = node;
			dfs(prox, l+1);
		}
	}
}

void init(){
	for (int j = 1; (1 << j) <= n; j++){
		for (int i = 1; i  <= n; i++){
			parent[i][j] = parent[parent[i][j-1]][j-1];
			mini[i][j] = min(mini[i][j-1], mini[parent[i][j-1]][j-1]);
			maxi[i][j] = max(maxi[i][j-1], maxi[parent[i][j-1]][j-1]);
		}
	}
}

ii solve(int u, int v){
	if (level[u] > level[v]) swap(u, v);

	int h = level[v] - level[u], menor = 1e9, maior = -1;
	for (int i=MAXLOG-1; i>=0; i--){
		if ((1 << i) <= h){
			h -= (1 << i);
			menor = min(mini[v][i], menor);
			maior = max(maxi[v][i], maior);
			v = parent[v][i];
		}
	}

	if (v == u) return make_pair(menor, maior);

	for (int i=MAXLOG-1; i>=0; i--){
		if (parent[u][i] != parent[v][i]){
			maior = max(maior, maxi[v][i]);
			maior = max(maior, maxi[u][i]);
			menor = min(menor, mini[v][i]);
			menor = min(menor, mini[u][i]);
			u = parent[u][i];
			v = parent[v][i];
		}
	}

	menor = min(menor, mini[u][0]);
	menor = min(menor, mini[v][0]);
	maior = max(maior, maxi[u][0]);
	maior = max(maior, maxi[v][0]);

	return make_pair(menor, maior);
}

int main(){
	int de, para, tam;
	scanf("%d", &n);

	for (int i=0; i<n-1; i++){
		scanf("%d %d %d", &de, &para, &tam);
		grafo[de].push_back(make_pair(para, tam));
		grafo[para].push_back(make_pair(de, tam));
	}

	dfs(1, 0);
	init();

	int q;
	scanf("%d", &q);
	for (int i=0; i<q; i++){
		scanf("%d %d", &de, &para);
		ii res = solve(de, para);
		printf("%d %d\n", res.first, res.second);	
	}


	return 0;
}