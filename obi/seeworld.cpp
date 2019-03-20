#include <bits/stdc++.h>
#define ll long long
#define ii pair <int, int>
#define MAXN 50002
using namespace std;

int n;
int cor[MAXN];
vector <int> grafo[MAXN];

bool dfs(int node, int c){
	cor[node] = c;

	for (int i=0; i<grafo[node].size(); i++){
		int prox = grafo[node][i];

		if (cor[prox] == c) 
			return false;

		if (cor[prox] == 0) 
			if (!dfs(prox, c == 1 ? 2 : 1)) 
				return false;
	}

	return true;
}

int main(){
	scanf("%d", &n);

	int num;
	bool res = true;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			scanf("%d", &num);
			if (num == 0){
				grafo[i].push_back(j);
			}
		}
	}

	for (int i=0; i<n; i++){
		if (cor[i] == 0){
			res = dfs(i, 1);
		}

		if (!res) break;
	}

	printf("%s\n", res ? "Bazinga!" : "Fail!");
	return 0;
}