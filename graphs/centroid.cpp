struct CentroidDecomposition {
	int sub[MAXN];
	bool sat[MAXN]; // Nodes saturados que n devem ser mais visitados
	int root;
	vector <int> tree[MAXN];

	CentroidDecomposition() {
		memset(sub, 0, sizeof sub);
		memset(sat, 0, sizeof sat);
		build(1, -1); // Levando em conta que o primeiro node eh 1
	}

	void build(int u, int p) {
		int n = dfs(u, p); // find the size of each subtree
		int centroid = dfs(u, p, n); // find the centroid
		if (p != -1) 
			tree[p].emplace_back(centroid),
			tree[centroid].emplace_back(p);
		else
			root = centroid;

		sat[centroid] = true;

		// for each tree resulting from the removal of the centroid
		for (int v : grafo[centroid])
			if (!sat[v]) build(v, centroid);
	}

	int dfs(int u, int p) {
		sub[u] = 1;

		for (int v : grafo[u])
			if (v != p && !sat[v]) sub[u] += dfs(v, u);

		return sub[u];
	}

	int dfs(int u, int p, int n) {
		for (int v : grafo[u])
			if (v != p && !sat[v] and sub[v] > n/2) return dfs(v, u, n);

		return u;
	}

} ctrd;
