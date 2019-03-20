#include <bits/stdc++.h>
#define ii pair <int, int>
using namespace std;

const int MAXN = 60000;
const int LOGMAXN = 20;

ii duplas[MAXN];
vector <int> grafo[MAXN];
int pai[MAXN][LOGMAXN], parent[MAXN], level[MAXN], n;

void preCompute(){
	memset(pai, -1, sizeof pai);

	for (int i=1; i<=n; i++){
		pai[i][0] = parent[i];
	}

	for (int j = 1; (1 << j) < n; j++){
		for (int i=1; i<=n; i++){
			if (pai[i][j-1] != -1){
				pai[i][j] = pai[pai[i][j-1]][j-1];
			}
		}
	}
}

int LCA(int u, int v){
	if (level[u] < level[v]) swap(u, v);

	int pulo, dist = level[u] - level[v], res = 0;

	while (dist > 0){
		pulo = log2(dist);
		u = pai[u][pulo];
		dist -= (1 << pulo);
		res += (1 << pulo);
	}

	if (u == v) return res;

	for (int j = log2(n); j >= 0; j--){
		if (pai[u][j] != -1 && pai[v][j] != -1 && (pai[u][j] != pai[v][j])){
			u = pai[u][j];
			v = pai[v][j];
			res += (1 << j) * 2;
		}
	}

	res += 2;
	return res;
}

bool visited[MAXN];
void dfs(int node){
	visited[node] = true;
	for (int i=0; i<grafo[node].size(); i++){
		if (!visited[grafo[node][i]]){
			parent[grafo[node][i]] = node;
			level[grafo[node][i]] = level[node] + 1;
			dfs(grafo[node][i]);
		}
	}
}

int main(){
	scanf("%d", &n);
	int aux, de, para;

	for (int i=1; i<=n; i++){
		scanf("%d", &aux);
		if (duplas[aux].first == 0) duplas[aux].first = i;
		else duplas[aux].second = i;
	}

	for (int i=0; i<n-1; i++){
		scanf("%d %d", &de, &para);
		grafo[de].push_back(para);
		grafo[para].push_back(de);
	}

	level[1] = 0;
	parent[1] = -1;
	dfs(1);
	preCompute();

	int res = 0;
	for (int i=1; i <= n/2; i++){
		res += LCA(duplas[i].first, duplas[i].second);
	}

	printf("%d\n", res);
	return 0;
}