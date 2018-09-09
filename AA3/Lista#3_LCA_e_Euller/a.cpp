#include <bits/stdc++.h>
#define mp make_pair
#define MAXN 10010
#define MAXLOG 20
#define ii pair <int, int>
#define ll long long
using namespace std;

vector <ii> grafo[MAXN];
int level[MAXN], parent[MAXN][MAXLOG], n, logs[MAXN], dist[MAXN][MAXLOG];
bool vis[MAXN];

void buildLCA(){
	for (int l=1; l<MAXLOG; l++){
		for (int i=1; i<=n; i++){
			parent[i][l] = parent[parent[i][l-1]][l-1];
			dist[i][l] = dist[parent[i][l-1]][l-1] + dist[i][l-1];
		}
	}
}

void dfs(int node, int l){
	vis[node] = true;
	for (int i=0; i<grafo[node].size(); i++){
		int prox = grafo[node][i].first;
		if (!vis[prox]){
			level[prox] = l + 1;
			parent[prox][0] = node;
			dist[prox][0] = grafo[node][i].second;
			dfs(prox, l+1);
		}
	}
}

ll qDist(int a, int b){
	if (level[a] > level[b]) swap(a, b);

	int distancia = level[b] - level[a], pulo;
	ll res = 0;
	while (distancia > 0){
		pulo = distancia & (-distancia);
		res += dist[b][logs[pulo]];
		b = parent[b][logs[pulo]];
		distancia -= pulo;
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

int qKth(int a, int b, int k){
	int x = a, y = b, lca;

	if (level[x] > level[y]) swap(x, y);

	int distancia = level[y] - level[x], pulo, caminho = 0;
	while (distancia > 0){
		pulo = distancia & (-distancia);
		y = parent[y][logs[pulo]];
		caminho += pulo;
		distancia -= pulo;
	}

	if (y == x){
		lca = y;
	} else {
		for (int i=MAXLOG-1; i>=0; i--){
			if (parent[x][i] != parent[y][i]){
				caminho += 1 << i;
				x = parent[x][i];
				y = parent[y][i];
			}
		}
		caminho += 2;
		lca = parent[x][0];		
	}


	if (k <= (level[a] - level[lca] + 1)){
		distancia = k - 1;
		while (distancia > 0){
			pulo = distancia & (-distancia);
			a = parent[a][logs[pulo]];
			distancia -= pulo;
		}
		return a;

	} else {
		distancia = (level[b] - level[lca]) + (level[a] - level[lca]) - k + 1;
		while (distancia > 0){
			pulo = distancia & (-distancia);
			b = parent[b][logs[pulo]];
			distancia -= pulo;
		}
		return b;
	}

}

int main(){
	int t;
	scanf("%d", &t);

	logs[0] = 0;
	logs[1] = 0;
	for (int i=2; i<MAXN; i++){
		logs[i] = logs[i>>1] + 1;
	}

	int de, para, kth, custo;
	while (t--){
		scanf("%d", &n);
		memset(dist, 0, sizeof dist);
		memset(parent, 0, sizeof parent);
		memset(level, 0, sizeof level);
		memset(vis, 0, sizeof vis);
		for (int i=1; i<= n; i++){grafo[i].clear();}
		level[1] = 1;

		for (int i=0; i<n-1; i++){
			scanf("%d %d %d", &de, &para, &custo);
			grafo[de].push_back(mp(para, custo));
			grafo[para].push_back(mp(de, custo));
		}

		dfs(1, 1);
		buildLCA();

		string query = "";
		cin >> query;
		while (query != "DONE"){
			if (query == "DIST"){
				scanf(" %d %d", &de, &para);
				printf("%lld\n", qDist(de, para));
			} else {
				scanf(" %d %d %d", &de, &para, &kth);
				printf("%d\n", qKth(de, para, kth));
			}
			cin >> query;
		}

		printf("\n");
	}

	return 0;
}