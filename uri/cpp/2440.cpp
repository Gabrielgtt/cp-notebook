#include <bits/stdc++.h>
using namespace std;

vector<int> grafo[1000000];
bool flags[1000000];
int v, e;

void dfs(int node){
	flags[node] = true;

	for (int i=0; i<grafo[node].size(); i++){
		if (flags[grafo[node][i]] == false){
			dfs(grafo[node][i]);
		}
	}
}

int main(){
	scanf("%d %d", &v, &e);
	
	int de, para;
	for (int i=0; i<e; i++){
		scanf("%d %d", &de, &para);
		grafo[de].push_back(para);
		grafo[para].push_back(de);
	}

	int res = 0;
	for (int i=1; i<=v; i++){
		if (flags[i] == false){
			res++;
			dfs(i);
		}
	}

	printf("%d\n", res);

	return 0;
}	