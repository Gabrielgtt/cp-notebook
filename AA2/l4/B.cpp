#include <bits/stdc++.h>
#define MAXN 100010
#define LOGMAXN 21
#define ii pair <int, int>
using namespace std;

int parent[MAXN][LOGMAXN], pai[MAXN], nodes;
unsigned long long int custo[MAXN];
vector <ii> grafo[MAXN];
int flag[MAXN], level[MAXN];

void construct(){
	for (int i = 0; i < nodes; i++){
		parent[i][0] = pai[i];
	}

	for (int j=1; j < 20; j++){
		for (int i=1; i < nodes; i++){
			if (parent[i][j-1] != - 1) parent[i][j] = parent[parent[i][j-1]][j-1];
		}
	}
}

unsigned long long int LCA(int u, int v){
	if (level[u] < level[v]) swap(u, v);

	int dist = level[u] - level[v], pulo;
	unsigned long long int somaU = custo[u], somaV = custo[v];
    // cout << "somaU = " << somaU << " somaV = " << somaV << endl;
    // cout << "levelU = " << level[u] << " levelV = " << level[v] << endl;

    // printf(">>dist = %d\n", dist);
	while (dist > 0){
		pulo = log2(dist);
        // printf("pulo = %d\n", pulo);
		u = parent[u][pulo];
        // printf("novoU = %d\n", u);
		dist -= (1 << pulo);
        // printf("dist = %d\n", dist);
	}

    // cout << "U = " << u << " V = " << v << " custo[u] = " << custo[u] << endl;
	if (u == v) return (somaU - custo[v]);

	for (int j = 20; j >= 0; j--){
		if (parent[u][j] != -1 && parent[v][j] != -1 && (parent[u][j] != parent[v][j])){
			u = parent[u][j];
			v = parent[v][j];
		}
	}

	return (somaU - (custo[pai[u]]*2) + somaV);
}


void dfs(int node){
	flag[node] = 1;
	// printf("Estou em %d\n", node);
	for (int i=0; i<grafo[node].size();i++){
		int atual = grafo[node][i].first;
		// printf("For de %d para %d\n", node, atual);
		if (flag[atual] == 0){
			level[atual] = level[node] + 1;
			pai[atual] = node;
			custo[atual] = grafo[node][i].second + custo[node];
			// printf("custo até %d = %lld\n", atual, custo[atual]);
			dfs(atual);
		}
	}
}

int main(){

	int destino, c;
	while (true) {
		scanf("%d", &nodes);
		if (nodes == 0) break;

		for (int i=0; i<=nodes; i++){
			grafo[i].clear();
		}

		// int parent[MAXN][LOGMAXN], pai[MAXN], nodes;
		// unsigned long long int custo[MAXN];
		// vector <ii> grafo[MAXN];
		// int flag[MAXN], level[MAXN];

		memset(parent, -1, sizeof parent);
		memset(custo, 0, sizeof custo);
		memset(pai, 0, sizeof pai);
		memset(level, 0, sizeof level);
		memset(flag, 0, sizeof flag);

		for (int i=1; i<nodes; i++){
			scanf("%d %d", &destino, &c);
			grafo[i].push_back(make_pair(destino, c));
			grafo[destino].push_back(make_pair(i, c));
		}

		level[0] = 1;
		pai[0] = 0;
		custo[0] = 0;
		// printf("\nGRAFO:\n");
		dfs(0);
		// printf("\n");
		construct();

		int q, n1, n2;
		scanf("%d", &q);
		for (int i=0; i<q; i++){
			scanf("%d %d\n", &n1, &n2);
			cout <<  LCA(n1, n2);

			if (i < q-1) printf(" ");
			else printf("\n");
		}

	}


	return 0;
}
