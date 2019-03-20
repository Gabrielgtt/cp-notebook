#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int MAXN = 10020;

int ouro[MAXN];
int n, c;

vector <ii> grafo[MAXN];

int dfs(int node, int pai, int aresta){
	int res = 0;
	for (int i=0; i<grafo[node].size(); i++){
		int prox = grafo[node][i].first;
		int dist = grafo[node][i].second;
		
		if (prox != pai){
			res += dfs(prox, node, dist);
		}
	}

	if (node != pai){
		ouro[pai] += ouro[node];
	}

	return res + (aresta * (((ouro[node]+c-1)/c)*2) );
}

int main(){
	scanf("%d %d", &n, &c);

	for (int i=1; i<=n; i++){
		scanf("%d", &ouro[i]);
	}

	int de, para, custo;
	for (int i=0; i<n-1; i++){
		scanf("%d %d %d", &de, &para, &custo);
		grafo[de].push_back(ii(para, custo));
		grafo[para].push_back(ii(de, custo));
	}

	printf("%d\n", dfs(1, 1, 0));
	return 0;
}