// ------------------------------------------------------------------------------ 
static const int N = 10001;

vector < pair <int, int> > graph[N];

int tree[4*N];
struct SegTree{
	SegTree(){ fill (tree, tree+(4*N), 0); }
	
	int query (int i, int j, int node=1, int a=1, int b=N){
		if (b < i || a > j) return 0;
		if (a >= i && b <= j) return tree[node];
		return max (query(i, j, node*2, a, (a + b)/2), query(i, j, node*2+1, (a + b)/2+1, b));
	}

	void update (int i, int value, int node=1, int a=1, int b=N){
		if (i < a || i > b) return;
		if (a == b){
			tree[node] = value;
			return;
		}
		update (i, value, node*2, a, (a+b)/2);
		update (i, value, node*2+1, (a+b)/2+1, b);
		tree[node] = max (tree[node*2], tree[node*2+1]);
	}
};


int heavy[N], parent[N], chain[N], depth[N];
int segidx[N], value[N];
struct HLD{
	SegTree s;
	
	void build(){
		dfs(1, 1, 0);
		int id = 1, v = 1;
		hld(v, v, id, v);
	}

	int dfs (int v, int p, int v_cost){
		int sz = 1, maxsz = 0;
		parent[v] = p;
		depth[v] = depth[p] + 1;
		value[v] = v_cost;
		heavy[v] = 0;
		for (int i = 0; i < graph[v].size(); i++){
			if (graph[v][i].first == p) continue;
			int subsz = dfs (graph[v][i].first, v, graph[v][i].second);
			if (subsz > maxsz){
				maxsz = subsz;
				heavy[v] = graph[v][i].first;
			}
			sz += subsz;
		}
		return sz;
	}

	void hld (int v, int p, int &idx, int c){
		segidx[v] = idx++;
		s.update(segidx[v], value[v]);
		chain[v] = c;
		if (heavy[v]) 
			hld (heavy[v], v, idx, c);
		for (int i = 0; i < graph[v].size(); i++)
			if (heavy[v] != graph[v][i].first && graph[v][i].first != p)
				hld(graph[v][i].first, v, idx, graph[v][i].first);
	}

	int query (int a, int b){
		int _max = 0;
		while (chain[a] != chain[b])
			if (depth[chain[a]] > depth[chain[b]])
				_max = max(_max, s.query(segidx[chain[a]], segidx[a])), a = parent[chain[a]];
			else
				_max = max(_max, s.query(segidx[chain[b]], segidx[b])), b = parent[chain[b]];

		if (a == b) return _max;
		return max (_max, s.query( min (segidx[a], segidx[b]) + 1, max(segidx[a], segidx[b])));
	}

	void change (int a, int b, int v){
		if (parent[a] == b)
			s.update(segidx[a], v);
		else
			s.update(segidx[b], v);
	}
};
// ------------------------------------------------------------------------------ 60877770026
