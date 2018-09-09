#include <bits/stdc++.h>
#define ll long long
#define ii pair <int, int>
#define MAXN 50002
using namespace std;

int n, m;

vector <int> grafo[MAXN];
int pais[MAXN];
vector <int> ans;

int main(){
	scanf("%d %d", &n, &m);

	int pai, filho;

	for (int i=0; i<m; i++){
		scanf("%d %d", &pai, &filho);
		grafo[pai].emplace_back(filho);
		pais[filho]++;
	}

	priority_queue <int, vector <int>, greater<int>> pq;
	for (int i=0; i<n; i++) if(pais[i] == 0) pq.push(i);

	while (!pq.empty()){
		int node = pq.top(); pq.pop();
		ans.emplace_back(node);

		for (int i=0; i<grafo[node].size(); i++){
			pais[grafo[node][i]]--;
			m--;
			if (pais[grafo[node][i]] == 0){
				pq.push(grafo[node][i]);
			}
		}
	}

	if (m > 0){
		printf("*\n");
	} else {
		for (int i=0; i<n; i++){
			printf("%d\n", ans[i]);
		}	
	}


	return 0;
}