#include <bits/stdc++.h>
#define MAXN 101000
#define MAXLOG 21
using namespace std;

int le[MAXN];
int pa[MAXLOG][MAXN];
static vector <int> grafo[MAXN];

template < vector<int> grafo[MAXN] > struct LCA {
	LCA(int n) {
		memset(le, 0, sizeof le);
		memset(pa, 0, sizeof pa);
		dfs(1, 0);
		for (int i=1; i<MAXLOG; i++)
			for (int j=1; j<=n; j++) // n = número de nodes no grafo
				pa[i][j] = pa[i-1][pa[i-1][j]];
	}

	void dfs(int v, int p, int l = 0) {
		for (int u : grafo[v]){
			if (u != p) {
				le[u] = l+1;
				pa[0][u] = v;
				dfs(u, v, l+1);
			}
		}
	}

	int dist(int u, int v) {
		if (le[u] > le[v]) swap(u, v);
		int res = 0;	
		for (int i=MAXLOG-1; i>=0; i--){
			if ((1 << i) <= (le[v] - le[u])) {
				res += 1 << i;
				v = pa[i][v];
			}
		}
		if (u == v) return res;
		for (int i=MAXLOG-1; i>=0; i--)
			if (pa[i][u] != pa[i][v]) {
				res += 1 << (i+1);
				u = pa[i][u];
				v = pa[i][v];
			}
		return res + 2;
	}
};


int main() {
	grafo[1].emplace_back(3);
	grafo[3].emplace_back(1);
	grafo[1].emplace_back(2);
	grafo[2].emplace_back(1);
	grafo[3].emplace_back(4);
	grafo[4].emplace_back(3);
	LCA <grafo> lca(4);
	assert(2 == lca.dist(1, 4));
	assert(3 == lca.dist(2, 4));
	return 0;
}
