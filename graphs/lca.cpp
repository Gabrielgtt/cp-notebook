#include <bits/stdc++.h>
#define MAXN 101000
#define MAXLOG 21
using namespace std;


int level[MAXN];
int papa[MAXLOG][MAXN];
struct LCA {

	LCA() {
		memset(level, 0, sizeof level);
		memset(papa, 0, sizeof papa);
		dfs(1, 0);
		build();
	}

	void dfs(int v, int p, int l = 0) {
		for (int u : grafo[v]){
			if (u != p) {
				level[u] = l+1;
				papa[0][u] = v;
				dfs(u, v, l+1);
			}
		}
	}

	void build() {
		for (int i=1; i<MAXLOG; i++)
			for (int j=1; j<=n; j++) // n = número de nodes no grafo
				papa[i][j] = papa[i-1][papa[i-1][j]];
	}

	int dist(int u, int v) {
		if (level[u] > level[v]) swap(u, v);
		int res = 0;	
		for (int i=MAXLOG-1; i>=0; i--){
			if ((1 << i) <= (level[v] - level[u])) {
				res += 1 << i;
				v = papa[i][v];
			}
		}
		if (u == v) return res;
		for (int i=MAXLOG-1; i>=0; i--)
			if (papa[i][u] != papa[i][v]){
				res += 1 << (i+1);
				u = papa[i][u];
				v = papa[i][v];
			}
		return res + 2;
	}

};

int main() {
	LCA lca = LCA();
	return 0;
}
