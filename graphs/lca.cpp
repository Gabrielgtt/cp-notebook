struct LCA {
	int level[MAXN];
	int parent[MAXLOG][MAXN];

	LCA() {
		memset(level, 0, sizeof level);
		memset(parent, 0, sizeof parent);
		dfs(1, 0);
		build();
	}

	void dfs(int node, int pai, int l = 0) {
		for (int filho : grafo[node]){
			if (filho != pai) {
				level[filho] = l+1;
				parent[0][filho] = node;
				dfs(filho, node, l+1);
			}
		}
	}

	void build() {
		for (int i=1; i<MAXLOG; i++){
			for (int j=1; j<=n; j++){ // n = número de node no grafo
				parent[i][j] = parent[i-1][parent[i-1][j]];
			}
		}
	}

	int dist(int u, int v) {
		if (level[u] > level[v]) swap(u, v);
		int res = 0;	

		for (int i=MAXLOG-1; i>=0; i--){
			if ((1 << i) <= (level[v] - level[u])) {
				res += 1 << i;
				v = parent[i][v];
			}
		}
		
		if (u == v) return res;

		for (int i=MAXLOG-1; i>=0; i--){
			if (parent[i][u] != parent[i][v]){
				res += 1 << (i+1);
				u = parent[i][u];
				v = parent[i][v];
			}
		}
		return res + 2;
	}
} lca;
