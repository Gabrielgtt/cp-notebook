#include <bits/stdc++.h>
#define MAXN 1002
#define ii pair <int, int>
#define mp make_pair
using namespace std;

int arr[MAXN], distS[MAXN], distT[MAXN];
vector <int> grafo[MAXN];
int adj[MAXN][MAXN];

int main(){
	int n, m, s, t;
	scanf("%d %d %d %d", &n, &m, &s, &t);

	int de, para;
	for (int i=0; i<m; i++){
		scanf("%d %d", &de, &para);
		grafo[de].push_back(para);
		grafo[para].push_back(de);
		adj[de][para] = 1;
		adj[para][de] = 1;
	}

	for (int i=0; i<MAXN; i++){
		distS[i] = 1e9;
		distT[i] = 1e9;
	}

	priority_queue < ii, vector <ii>, greater <ii> > pq;
	distS[s] = 0;
	pq.push(mp(0, s));

	while (!pq.empty()){
		ii atual = pq.top(); pq.pop();
		
		if (atual.first > distS[atual.second]) continue;

		for (int i=0; i<grafo[atual.second].size(); i++){
			int prox = grafo[atual.second][i];

			if (atual.first + 1 < distS[prox]){
				distS[prox] = atual.first + 1;
				pq.push(mp(distS[prox], prox));
			}
		}
	}

	pq.push(mp(0, t));
	distT[t] = 0;

	while (!pq.empty()){
		ii atual = pq.top(); pq.pop();

		if (atual.first > distT[atual.second]) continue;

		for (int i=0; i<grafo[atual.second].size(); i++){
			int prox = grafo[atual.second][i];

			if (atual.first + 1 < distT[prox]){
				distT[prox] = atual.first + 1;
				pq.push(mp(distT[prox], prox));
			}
		}
	}

	int menor = distT[s], res = 0;

	for (int i=1; i<=n; i++){
		for (int j=i+1; j<=n; j++){
			if (adj[i][j] == 0){
				if (distT[i] + 1 + distS[j] >= menor && distT[j] + 1 + distS[i] >= menor){
					res++;
				}
			}
		}
	}

	printf("%d\n", res);
	return 0;
}