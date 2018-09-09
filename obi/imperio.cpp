#include <bits/stdc++.h>
#define MAXN 200000
using namespace std;

vector <int> grafo[MAXN];
int n;
int res; 

int solve(int node, int pai){
	int soma = 1;
	for (int i=0; i<grafo[node].size(); i++){
		if (grafo[node][i] != pai){
			soma += solve(grafo[node][i], node);
		}
	}
	res = min(res, abs(abs(n - soma) - soma));
	return soma;
}

int main(){
	scanf("%d", &n);
	res = n-1;
	int de, para;
	for (int i=0; i<n-1; i++){
		scanf("%d %d", &de, &para);
		grafo[de].push_back(para);
		grafo[para].push_back(de);
	}

	solve(1, 0);
	printf("%d\n", res);
	return 0;
}