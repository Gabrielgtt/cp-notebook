#include <bits/stdc++.h>
#define MAXN 100010
#define ll long long
#define mp make_pair
#define eb emplace_back
#define ii pair <int, int>
using namespace std;

vector <int> grafo[MAXN];
vector <int> *verts[MAXN];
int cores[MAXN], n, tam[MAXN], pesada[MAXN], maior = 0;
ll final[MAXN], freq[MAXN], cor[MAXN];

void dfs(int atual, int pai){
	tam[atual] = 1;
	pesada[atual] = -1;
	int ma = -1; 
	for (int i=0; i<grafo[atual].size(); i++){
		int prox = grafo[atual][i];
		if (prox != pai){
			dfs(prox, atual);
			if (tam[prox] > ma) ma = tam[prox], pesada[atual] = prox;
			tam[atual] += tam[prox];
		}
	}
}

void sack(int atual, int pai, bool keep){
	for (auto prox : grafo[atual]){
		if (prox != pai && prox != pesada[atual]){
			sack(prox, atual, 0);
		}
	}

	if (pesada[atual] == -1){
		verts[atual] = new vector <int> ();
	} else {
		sack(pesada[atual], atual, true);
		verts[atual] = verts[pesada[atual]];
	}

	verts[atual]->push_back(atual);

	freq[cores[cor[atual]]] -= cor[atual];
	cores[cor[atual]]++;
	freq[cores[cor[atual]]] += cor[atual];
	maior = max(maior, cores[cor[atual]]);

	for (auto prox : grafo[atual]){
		if (prox != pai && prox != pesada[atual]){
			for (auto outro : *verts[prox]){
				freq[cores[cor[outro]]] -= cor[outro];
				cores[cor[outro]]++;
				freq[cores[cor[outro]]] += cor[outro];
				maior = max(maior, cores[cor[outro]]);
				verts[atual]->push_back(outro);
			}	
		}
	}

	final[atual] = freq[maior];

	if (!keep){
		for (auto prox : *verts[atual]){
			freq[cores[cor[prox]]] -= cor[prox];
			if (freq[maior] == 0) maior--;
			cores[cor[prox]]--;
			freq[cores[cor[prox]]] += cor[prox];
		}
	}
}		

int main(){
	scanf("%d", &n);
	for (int i=1; i<=n; i++){
		scanf("%lld", &cor[i]);
	}
	int de, para;
	for (int i=0; i<n-1; i++){
		scanf("%d %d", &de, &para);
		grafo[de].eb(para);
		grafo[para].eb(de);
	}
	dfs(1, 0);
	sack(1, 0, true);
	for (int i=1; i<=n; i++){
		if (i > 1) printf(" ");
		printf("%lld", final[i]);
	}
	printf("\n");

	return 0;
}