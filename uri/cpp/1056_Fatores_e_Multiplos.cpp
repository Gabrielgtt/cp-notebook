#include <bits/stdc++.h>
#define MAXN 2001011
#define ii pair<int, int>

using namespace std;

int preto=0, branco=0;

int maxMatching(){
	
}

void dfs(int start, vector<int> grafo[], int cor[], int corzin){
	printf("--Estou em <%d>, pintando-o de %d\n", start, corzin);
	if (corzin == 1) preto++;
	if (corzin == -1) branco++;

	cor[start] = corzin;

	if (corzin == 1) {
		corzin = -1;
	} else { corzin = 1;}

	for (int j=0; j<grafo[start].size(); j++){

		if (cor[grafo[start][j]] == 0){
			printf("--recursao de %d para %d\n", start, grafo[start][j]);
			dfs(grafo[start][j], grafo, cor, corzin);
		}
	}
}

int main(){
	int num_casos;
	scanf("%d", &num_casos);

	for (int caso=1; caso <= num_casos; caso++){

		int grupos[A+B]; // Unindo os grupos

		int A;
		scanf("%d", &A);
		int grupoA[A], num;

		for (int i=0; i<A; i++){
			scanf("%d", &grupos[i]);
		}

		int B;
		scanf("%d", &B);
		int grupoB[B];

		for (int i=A; i<A+B; i++){
			scanf("%d", &grupos[i]);
		}

		vector<int> grafo[A+B];// Criar grafo
		
		for (int b=A; b < A+B; b++){
			for (int a=0; a < A; a++){

				if (grupos[a] != 0){
					if (grupos[b] % grupos[a] == 0){
						grafo[b].push_back(a);
						grafo[a].push_back(b);
					}
				} else {
					
					if (grupos[b] == 0){
						grafo[b].push_back(a);
						grafo[a].push_back(b);

					}
				}
			}
		}

		printf("\nGRAFO:\n");
		for (int i=0; i<A+B; i++){
			printf("%d >> ", i);
			for (int j=0; j<grafo[i].size(); j++){
				printf("%d ", grafo[i][j]);
			}
			printf("\n");
		}
		printf("---------------------\n\n");

		int cor[A+B], res=0;
		memset(cor, 0, sizeof cor);

		for (int index=0; index < A+B; index++){
			printf("Checar se %d já foi pintado\n", index);
			if (cor[index] == 0 && grafo[index].size() != 0){
				// printf("Nao foi, agora a DFS()\n");
				dfs(index, grafo, cor, 1);

				printf("DFS acabou\n>>preto = %d\n>>branco = %d\n\n", preto, branco);
	
				if (preto < branco) {
					res += preto;
				} else {
					res += branco;
				}
			}

			preto = 0; branco = 0;
		}


		printf("Case %d: %d\n", caso, res);

	}

	return 0;
}