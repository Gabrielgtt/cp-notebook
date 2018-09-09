#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
const int MAXN = 20000;

vector <ii> grafo[MAXN][2];

int dfs(int node, int tipo, int descida){
	int res = descida;
	for (int i=0; i<grafo[node][tipo].size(); i++){
		int prox = grafo[node][tipo][i].first;
		int t = grafo[node][tipo][i].second;

		if (t == 1){
			res = max(res, dfs(prox, tipo, descida+1));
		} else {
			res = max(res, dfs(prox, tipo, 1));
		}
	}
	return res;
}

int firstPath(int node, int tipo){
	for (int i=0; i<grafo[node][tipo].size(); i++){
		int prox = grafo[node][tipo][i].first;
		int t = grafo[node][tipo][i].second;

		if (t == 1){
			return 1 + firstPath(prox, tipo);
		}
	}
	return 1;
}

int main(){
	int n;
	scanf("%d", &n);

	int vert, central, left, right;
	for (int i=0; i<n; i++){
		scanf("%d %d %d", &vert, &left, &central);

		if (left != 0) grafo[vert][1].push_back(make_pair(left, 2));
		if (central != 0) grafo[vert][1].push_back(make_pair(central, 1));
	}

	int m;
	scanf("%d", &m);

	for (int i=0; i<m; i++){
		scanf("%d %d %d", &vert, &central, &right);

		if (right != 0) grafo[vert][2].push_back(make_pair(right, 2));
		if (central != 0) grafo[vert][2].push_back(make_pair(central, 1));
	}

	printf("%d\n", n+m-max(min(firstPath(1, 1), dfs(1, 2, 1)), min(firstPath(1, 2), dfs(1, 1, 1))));
	
	return 0;
}