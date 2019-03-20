#include <bits/stdc++.h>

using namespace std;

typedef struct {
	int origem;
	int destino;
	int custo;
} aresta;

int tem_ciclos(int parents[], int origem, int destino){

	while (parents[origem] > -1){
		origem = parents[origem];
	}

	while (parents[destino] > -1){
		destino = parents[destino];
	}

	if (origem != destino){
		parents[destino] = origem;
		return 1;
	}
	return 0;
}

bool comp(aresta x, aresta y) {return x.custo < y.custo;}

int main(){
	while (1){
		int verts, edges; 
		scanf("%d %d", &verts, &edges);

		if (verts == 0 || edges == 0){break;}

		int parents[verts]; aresta grafo[edges];
		int custo = 0, custo_total = 0;

		for(int i=0;i<verts;i++){parents[i]=-1;}

		for (int i=0; i<edges; i++){
			scanf("%d %d %d", &grafo[i].origem, &grafo[i].destino, &grafo[i].custo);
			custo_total += grafo[i].custo;
		}

		sort(grafo, grafo + edges, comp);

		int i = 0, j = 1;
		while ( j < verts && i < edges){
			if (tem_ciclos(parents, grafo[i].origem, grafo[i].destino)){
				custo += grafo[i].custo;
				j++;
			}
			i++;
		}
		printf("%d\n", custo_total - custo);

	}
	return 0;
}