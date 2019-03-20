#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define ii pair <int, int>
#define f first
#define s second
#define INF 1e9
#define MAXN 102000
#define MAXLOG 25
#define MOD 1000000007
using namespace std;

vector < pair <int, ii> > grafo[MAXN];
int level[MAXN], parent[MAXN][MAXLOG], n, logs[MAXN];
ll dist[MAXN][MAXLOG][2];
bool vis[MAXN];

void buildLCA(){
	for (int l=1; l<MAXLOG; l++){
		for (int i=1; i<=n; i++){
			parent[i][l] = parent[parent[i][l-1]][l-1];
			dist[i][l][0] = dist[parent[i][l-1]][l-1][0] + dist[i][l-1][0];
			dist[i][l][1] = dist[parent[i][l-1]][l-1][1] + dist[i][l-1][1];
		}
	}
}

ll solve(int de, int para){
	int ctrl = 1;
	if (level[de] > level[para]) swap(de, para), ctrl ^= 1;

	int distancia = level[para] - level[de], pulo;
	ll res = 0;
	while (distancia > 0){
		pulo = distancia & (-distancia);
		res += dist[para][logs[pulo]][ctrl];
		para = parent[para][logs[pulo]];
		distancia -= pulo;
	}	

	if (para == de) return res;

	for (int i=MAXLOG-1; i>=0; i--){
		if (parent[de][i] != parent[para][i]){
			res += dist[de][i][ctrl^1];
			res += dist[para][i][ctrl];
			de = parent[de][i];
			para = parent[para][i];
		}
	}

	res += dist[de][0][ctrl^1];
	res += dist[para][0][ctrl];

	return res;
}


void dfs(int node, int l){
	vis[node] = true;
	for (int i=0; i<grafo[node].size(); i++){
		int prox = grafo[node][i].first;
		if (!vis[prox]){
			level[prox] = l + 1;
			parent[prox][0] = node;
			dist[prox][0][0] = grafo[node][i].s.f;
			dist[prox][0][1] = grafo[node][i].s.s;
			dfs(prox, l+1);
		}
	}
}

int main(){
	int t;
	scanf("%d", &t);

	logs[1] = logs[0] = 0;
	for (int i=2; i<MAXN; i++){
		logs[i] = logs[i/2] + 1;
	}

	while (t--){
		scanf("%d", &n);
		for (int i=0; i<=n; i++){
			grafo[i].clear();
			vis[i] = false;
		}

		ll soma = 0;
		int de, para, ida, vinda;
		for (int i=0; i<n-1; i++){
			scanf("%d %d %d %d", &de, &para, &ida, &vinda);
			soma += (ll) (ida + vinda);
			grafo[de].emplace_back(mp(para, mp(ida, vinda)));
			grafo[para].emplace_back(mp(de, mp(vinda, ida)));
		}

		dfs(1, 0);
		buildLCA();

		int q;
		scanf("%d", &q);

		while (q--){
			scanf("%d %d", &de, &para);
			printf("%lld\n", soma - solve(de, para));
		}
	}

	return 0;
}