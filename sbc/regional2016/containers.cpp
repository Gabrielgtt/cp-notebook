#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

typedef pair <int, string> P;

int a1[] = {0, 1, 2, 4, 5, 6, 0, 1, 2, 3};
int a2[] = {1, 2, 3, 5, 6, 7, 4, 5, 6, 7};

string source;
string sink;

int entrada[10];
int saida[10];

map <string, int> dist;
map <string, bool> vis;

P pular(string node, int l, int r){
	swap(node[l], node[r]);
	return P(entrada[node[l] - '0'] + entrada[node[r] - '0'], node);
}

int main(){
	
	map <int, int> cont;

	for (int i=0; i<8; i++){
		scanf("%d", &entrada[i]);
		if (cont[entrada[i]] == 0){
			cont[entrada[i]] = i+1;
		} 
		source += '0' + (cont[entrada[i]] - 1);
	}

	for (int i=0; i<8; i++){
		scanf("%d", &saida[i]);
		sink += '0' + cont[saida[i]] - 1;
	}

	priority_queue <P, vector <P>, greater <P> > pq;
	pq.push(P(0, source));
	dist[source] = 0;
	vis[source] = true;

	while (!pq.empty()){
		P atual = pq.top(); pq.pop();

		if (atual.f > dist[atual.s]) continue;

		for (int i=0; i<10; i++){
			P prox = pular(atual.s, a1[i], a2[i]);

			if (!vis[prox.s]){
				vis[prox.s] = true;
				dist[prox.s] = 1e9;
			}

			if (atual.f + prox.f < dist[prox.s]){
				dist[prox.s] = atual.f + prox.f;
				pq.push(P(atual.f + prox.f, prox.s));
			}
		}
	}

	printf("%d\n", dist[sink]);

	return 0;
}