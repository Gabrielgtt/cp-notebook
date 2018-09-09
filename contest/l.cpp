#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define ii pair <int, int> 
#define MAXN 100010
#define MAXLOG 20
using namespace std;

vector <int> grafo[MAXN];
bool vis[MAXN];

int dfs(int node){
	vis[node] = true;
	int res = 0;

	for (int i=0; i<grafo[node].size(); i++){
		if (!vis[grafo[node][i]]){
			res = max(dfs(grafo[node][i]), res);
		}
	}

	return res+1;
}

int main(){
	int n, a;

	int de , para;

	scanf("%d %d", &n, &a);

	for (int i=0; i<n-1; i++){
		scanf("%d %d", &de, &para);
		grafo[de].push_back(para);
		grafo[para].push_back(de);
	}

	printf("%d\n", dfs(a));

	return 0;
}