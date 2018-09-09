#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define ii pair <int, int>
#define f first
#define s second
#define iq pair<int, queue <char>>
#define INF 1e9
#define MOD 1000000007
#define eb emplace_back
#define MAXN 100012
#define MAXLOG 22
#define MAXCOR 102
#define debug(x) cerr << #x << " = " << x << endl
#define debug_arr(x, tam) cerr << #x << " = "; for (int i=0;i<tam;i++) cout << x[i] << " "; printf("\n")
using namespace std;

int n;

int lca1[MAXN][MAXLOG], lca2[MAXN][MAXLOG];
int level1[MAXN], level2[MAXN];
ll dist1[MAXN][MAXLOG], dist2[MAXN][MAXLOG];
int logs[MAXN];
vector< pair <int, ll> > grafo[MAXN];
bool vis[MAXN];

void buildLCA(){
	for (int i=1; (1<<i) <= n; i++){
		for (int j=1; j<=n; j++){
			lca1[j][i] = lca1[lca1[j][i-1]][i-1];
			lca2[j][i] = lca2[lca2[j][i-1]][i-1];
			dist1[j][i] = dist1[j][i-1] + dist1[ lca1[j][i-1] ][i-1];
			dist2[j][i] = dist2[j][i-1] + dist2[ lca2[j][i-1] ][i-1];
		}
	}
}

bool gamb = true;

void dfs(int atual, int pai, ll dist){
	vis[atual] = true;
	lca1[atual][0] = pai;
	dist1[atual][0] = dist;
	level1[atual] = level1[pai] + 1;

	lca2[atual][0] = pai;
	dist2[atual][0] = dist;
	level2[atual] = level2[pai] + 1;

	for (int i=0; i<grafo[atual].size(); i++){
		int prox = grafo[atual][i].f;
		if (prox == pai) continue;

		dist2[prox][0] = grafo[atual][i].s;

		if (vis[prox]){
			if (gamb){
				dist2[atual][0] = grafo[atual][i].s;
				lca2[atual][0] = prox;
				level2[atual] = level1[prox]+1;
				gamb = false;
			} 	
		} else{
			dfs(prox, atual, grafo[atual][i].s);
		}
		
	}
}

ll query1(int u, int v){
	if (level1[u] > level1[v]){
		swap(u, v);
	}
	ll res = 0;

	int dist = level1[v] - level1[u], pulo;

	while (dist){
		pulo = dist & (-dist);
		res += dist1[v][logs[pulo]];
		v = lca1[v][logs[pulo]];
		dist -= pulo;
	}

	if (u == v) return res;

	for (int i=MAXLOG-1; i>=0; i--){
		if (lca1[u][i] != lca1[v][i]){
			res += dist1[u][i];
			res += dist1[v][i];
			u = lca1[u][i];
			v = lca1[v][i];
		}
	}

	res += dist1[u][0];
	res += dist1[v][0];

	return res;
}

ll query2(int u, int v){
	// printf("q2 de %d %d\n", u, v);
	if (level2[u] > level2[v]){
		swap(u, v);
	}
	ll res = 0;

	int dist = level2[v] - level2[u], pulo;

	// printf("level2[%d] = %d\n", v, level2[v]);
	// printf("level2[%d] = %d\n", u, level2[u]);
	while (dist){
		pulo = dist & (-dist);
		// printf("dist = %d\n", dist);
		// printf("dist2[%d][%d] = %lld\n", v, logs[pulo], dist2[v][logs[pulo]]);
		res += dist2[v][logs[pulo]];

		// printf("%d - > ", v);
		v = lca2[v][logs[pulo]];
		// printf("%d\n", v);
		dist -= pulo;
	}

	// printf("res esta em %lld\n", res);
	if (u == v) return res;

	for (int i=MAXLOG-1; i>=0; i--){
		if (lca2[u][i] != lca2[v][i]){
			res += dist2[u][i];
			res += dist2[v][i];
			u = lca2[u][i];
			v = lca2[v][i];
		}
	}

	res += dist2[u][0];
	res += dist2[v][0];
	
	return res;
}


int main(){
	int t;
	scanf("%d", &t);
	int q, de, para, custo;

	logs[0] = logs[1] = 0;
	for (int i=2; i<MAXN; i++){
		logs[i] = logs[i/2] + 1;
	}

	while(t--){
		scanf("%d %d", &n, &q);
		for (int i=1; i<=n; i++){
			grafo[i].clear();
		}
		gamb = true;
		memset(vis, 0, sizeof vis);
		memset(lca1, 0, sizeof lca1);
		memset(lca2, 0, sizeof lca2);
		memset(dist1, 0, sizeof dist1);
		memset(dist2, 0, sizeof dist2);

		for (int i=0; i<n; i++){
			scanf("%d %d %d", &de, &para, &custo);
			grafo[de].eb(mp(para, custo));
			grafo[para].eb(mp(de, custo));
		}

		dfs(1, 0, 0);
		buildLCA();

		for (int i=0; i<q; i++){
			scanf("%d %d", &de, &para);
			printf("%lld\n", min(query1(de, para), query2(de, para)));
		}
	}
	return 0;
}