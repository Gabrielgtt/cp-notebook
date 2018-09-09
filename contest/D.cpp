#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define ii pair <int, int> 
#define MAXN 500010
using namespace std;

vector <int> grafo[MAXN];
int pai[MAXN];
int res[MAXN];
int sz[MAXN];

void dfs(int node, int papa){
	pai[node] = papa;
	for (int prox : grafo[node]){
		if (prox != papa){
			sz[node]++;
			dfs(prox, node);
		}
	}
}

int main(){
	int n;

	scanf("%d", &n);

	int de, para;
	for (int i=0; i<n-1; i++){
		scanf("%d %d", &de, &para);
		grafo[de].push_back(para);
		grafo[para].push_back(de);
	}

	dfs(1, 0);
	int num;
	int idx = 1;

	for (int i=0; i<n; i++){
		scanf("%d", &num);
		if (res[i] != pai[num]){
			printf("No\n");
			return 0;
		}
		while (sz[num]--){
			res[idx++] = num;
		}
	}

	printf("%s\n", "Yes");
	return 0;
}