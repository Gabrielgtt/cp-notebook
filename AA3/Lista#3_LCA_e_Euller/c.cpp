#include <bits/stdc++.h>
#define MAXN 100010
#define pb push_back
#define LOG 22
using namespace std;

int n, level[MAXN], parent[MAXN][LOG], logs[MAXN];
vector <int> grafo[MAXN];

void dfs(int atual, int prof){
	for (int i=0; i<grafo[atual].size(); i++){
		int prox = grafo[atual][i];
		if (prox != atual){
			level[prox] = prof + 1;
			parent[prox][0] = atual;
			dfs(prox, prof+1);			
		}
	}
}

void buildLca(){
	for (int log = 1; log < LOG; log++){
		for (int i = 1; i <= n; i++){
			parent[i][log] = parent[parent[i][log-1]][log-1];
		}
	}
}

int query(int u, int v){
	if (level[u] > level[v]) swap(u, v);

	int dist = level[v] - level[u], total = 0, pulo;

	while (dist > 0){
		pulo = dist & (-dist);
		total += pulo;
		v = parent[v][logs[pulo]];
		dist -= pulo;
	}

	if (u == v) return total;

	for (int i=LOG-1; i>=0; i--){
		if (parent[u][i] != parent[v][i]){
			total += (1 << (i+1));
			u = parent[u][i];
			v = parent[v][i];
		}
	}

	return total+2;
}

int main(){
	int t;
	scanf("%d", &t);

	logs[0] = logs[1] = 0;
	for (int i=2; i<MAXN; i++){
		logs[i] = logs[i>>1]+1;
	}

	while (t--){
			
		scanf("%d", &n);

		for (int i=0; i<=n; i++) grafo[i].clear();

		int num;
		for (int i=2; i<=n; i++){
			scanf("%d", &num);
			grafo[num].pb(i);
		}

		memset(parent, 0, sizeof parent);
		level[1] = 1;
		dfs(1, 1);
		buildLca();

		int p1 = 1, p2 = 2, maiorDist = 0, dist;
		for (int i = 2; i <= n; i++){
			dist = query(p1, i);
			if (dist > maiorDist){
				maiorDist = dist;
				p2 = i;
			} else if ((dist = query(p2, i)) > maiorDist) {
				maiorDist = dist;
				p1 = i;				
			}
			printf("%d\n", maiorDist);
		}
	}
	return 0;
}