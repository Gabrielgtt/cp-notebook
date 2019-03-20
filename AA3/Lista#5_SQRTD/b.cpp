#include <bits/stdc++.h>
#define pb push_back
#define LOG 22
#define MAXN 100002
using namespace std;

int pesos[MAXN], logs[MAXN], euler[MAXN], indexEuler = 0, levels[MAXN], n, m, parent[MAXN][LOG];
int res[MAXN], freq[MAXN], raiz, dupla[MAXN], total, ini[MAXN], fim[MAXN];
vector <int> grafo[MAXN];

struct query{
	int id, left, right, paizao;
	bool tipo;
} qs[MAXN];

void buildLogs(){
	logs[0] = logs[1] = 0;
	for (int i=2; i<MAXN; i++){
		logs[i] = logs[i/2]+1;
	}
}

void buildEuler(int node, int pai){
	ini[node] = indexEuler;
	euler[indexEuler++] = node;
	for (int i=0; i<grafo[node].size(); i++){
		if (grafo[node][i] != pai){
			buildEuler(grafo[node][i], node);
		}
	}
	fim[node] = indexEuler;
	euler[indexEuler++] = node;
}

void dfsLevels(int node, int pai, int level){
	for (int i=0; i<grafo[node].size(); i++){
		if (grafo[node][i] != pai){
			levels[grafo[node][i]] = level+1;
			parent[grafo[node][i]][0] = node;
			dfsLevels(grafo[node][i], node, level+1);
		}
	}
}

void buildLCA(){
	dfsLevels(1, 0, 0);

	for (int i=1; i<LOG; i++){
		for (int j=1; j<=n; j++){
			parent[j][i] = parent[parent[j][i-1]][i-1];
		}
	}
}

int lca(int u, int v){
	if (levels[u] > levels[v]) swap(u, v);

	int dist = levels[v] - levels[u], pulo;

	while (dist > 0){
		pulo = dist & (-dist);
		v = parent[v][logs[pulo]];
		dist -= pulo;
	}

	if (u == v) {
		return v;
	}
	for (int i=LOG-1; i>=0; i--){
		if (parent[u][i] != parent[v][i]){
			u = parent[u][i];
			v = parent[v][i];
		}
	}

	return parent[u][0];
}

bool comp(query a, query b){
	if (a.left/raiz == b.left/raiz) return a.right < b.right;
	return a.left/raiz < b.left/raiz;
}

int sub(int index){
	dupla[euler[index]]--;

	if (dupla[euler[index]] == 1){

		freq[pesos[euler[index]]]++;
		if (freq[pesos[euler[index]]] == 1){
			total++;
		}

	} else if (dupla[euler[index]] == 0){

		freq[pesos[euler[index]]]--;
		if (freq[pesos[euler[index]]] == 0){
			total--;
		}

	}
}

int add(int index){
	dupla[euler[index]]++;

	if (dupla[euler[index]] == 1){

		freq[pesos[euler[index]]]++;
		if (freq[pesos[euler[index]]] == 1){
			total++;
		}

	} else if (dupla[euler[index]] == 2){

		freq[pesos[euler[index]]]--;
		if (freq[pesos[euler[index]]] == 0){
			total--;
		}

	}
}


void solve(){
	int left = 1, right = 0;

	for (int i=0; i<m; i++){

		while(left < qs[i].left){
			sub(left++);
		}
		while (qs[i].left < left){
			add(--left);
		}
		while (right < qs[i].right){
			add(++right);
		}
		while (qs[i].right < right){
			sub(right--);
		}

		res[qs[i].id] = total;

		if (!qs[i].tipo){
			if (freq[pesos[qs[i].paizao]] == 0){
				res[qs[i].id]++;
			}
		}

	}

	for (int i=0; i<m; i++){
		if (i > 0) printf(" ");
		printf("%d", res[i]);
	}
	printf("\n");
}


int main(){
	int de, para;
	scanf("%d %d", &n, &m);
	raiz = sqrt(m);
	map <int, int> mask;
	int code = 1, num;
	for (int i=1; i<=n; i++){
		scanf("%d", &num);

		if (mask[num] == 0){
			mask[num] = code++;
		}

		pesos[i] = mask[num];
	}
	
	for (int i=0; i<n-1; i++){
		scanf("%d %d", &de, &para);
		grafo[de].pb(para);
		grafo[para].pb(de);
	}

	buildLogs();
	buildLCA();
	buildEuler(1, 0);

	for (int i=0; i<m; i++){
		scanf("%d %d", &de, &para);
		qs[i].id = i;
		qs[i].paizao = lca(de, para);
		qs[i].tipo = qs[i].paizao == de || qs[i].paizao == para;

		if (qs[i].tipo){
			qs[i].left = min(ini[de], ini[para]);
			qs[i].right = max(ini[de], ini[para]);
		} else {
			qs[i].left = min(fim[de], fim[para]);
			qs[i].right = max(ini[para], ini[de]);			
		}
	}

	sort(qs, qs+m, comp);

	solve();

	return 0;
}