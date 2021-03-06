#define INF 1e9
#define MAXN 100007

struct edge {
    int to, cap, rev;
    edge(int _to, int _cap, int _rev): to(_to), cap(_cap), rev(_rev){}
};

// ------------------------------------------------------------------------------ 
struct dinic {
    vector<edge> graph[MAXN];
    int level[MAXN], iter[MAXN];

    dinic() {
        fill(level, level+MAXN, 0);
        fill(iter, iter+MAXN, 0);
    }

    void add(int from, int to, int cap) {
        graph[from].push_back(edge(to, cap, graph[to].size()));
        graph[to].push_back(edge(from, 0, graph[from].size()-1));
    }

    void bfs(int s) {
        memset(level, -1, sizeof level);
        queue<int> q;
        level[s] = 0;
        q.push(s);
        while( !q.empty() ) {
            int actual = q.front();
            q.pop();
            for(int i = 0; i < graph[actual].size(); i++) {
                edge &e = graph[actual][i];
                if(e.cap > 0 && level[e.to] < 0){
                    level[e.to] = level[actual] + 1;
                    q.push(e.to);
                }
            }
        }
    }

    int dfs(int v, int t, int f) {
        if(v == t) return f;
        for(int &i = iter[v]; i < graph[v].size(); i++) {
            edge &e = graph[v][i];
            if(e.cap > 0 && level[v] < level[e.to]){
                int d = dfs(e.to, t, min(f, e.cap));
                if(d > 0){
                    e.cap -= d;
                    graph[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    int flow(int start, int to) {
        int ans = 0;
        while(true){
            bfs(start);
            if(level[to] < 0) return ans;
            int f;
            memset(iter, 0, sizeof iter);
            while((f = dfs(start, to, INF)) > 0) ans += f;
        }
    }
};
// ------------------------------------------------------------------------------ 31271989117


// ------------------------------------------------------------------------------ 
vector <int> grafo[MAXN];
bool vis[MAXN];

void gogo(int v, vector <int> &mvc, bool left = true) {
	vis[v] = true;
	for (int u : grafo[v]) {
		if (!vis[u]) {
			if (left) mvc.emplace_back(u);
			gogo(u, mvc, !left);
		}
	}
}

// Retorna um vector com os vertices do min vertex cover (dado que o fluxo já foi feito)
vector <int> min_vertex_cover(int lx, int rx) {
	for (int i=0; i<MAXN; i++) grafo[i].clear(), vis[i] = false;;
	vector <int> starts;
	for (int i=lx; i<=rx; i++) {
		bool tem = false;
		for (edge u : graph[i]) {
			if (u.to >= MAXN-2) continue; // exclua os vértices de sink e source
			if (u.cap == 0) {
				tem = true;
				grafo[u.to].emplace_back(i);	
			} else {
				grafo[i].emplace_back(u.to);
			}
		}
		if (!tem) starts.emplace_back(i);
	}
	vector <int> res;
	for (int v : starts) gogo(v, res);
	for (int i=lx; i<=rx; i++) if (!vis[i]) res.emplace_back(i);
	return res;
}

// ------------------------------------------------------------------------------ 
