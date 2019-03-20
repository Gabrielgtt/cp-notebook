#include <bits/stdc++.h>

using namespace std;

int cont = 0;

void dfs(vector<int> mapa[], int start, int flags[]){
	if (flags[start]){
		// printf("Olha o flagado aqui >>> %d\n", start);
		return;
	} else {
		// printf("%d Nao esta em flags, mas estara\n", start);
		flags[start] = 1; cont += 1;
		for (int i=0; i<mapa[start].size(); i++){
			// printf("Indo para %d\n", mapa[start][i]);
			dfs(mapa, mapa[start][i], flags);
		}
	}
}

int main(){
	int verts, edges, origem, destino, mao;

	while (1){
		cont = 0;
		scanf("%d %d", &verts, &edges);
		if (verts == 0 && edges == 0){break;}
		verts++;
		vector<int> mapa[verts];
		int flags[verts];

		for (int i=0; i<verts; i++){flags[i] = 0;}


		for (int i=0; i<edges; i++){
			scanf("%d %d %d", &origem, &destino , &mao);
			mapa[origem].push_back(destino);
			if (mao == 2){
				mapa[destino].push_back(origem);
			}
		}

		// printf("Grafo:\n");
		// for (int i=0; i<verts; i++){
		// 	printf("%d---> ", i);
		// 	for(int k=0; k<mapa[i].size(); k++){
		// 		printf("%d ", mapa[i][k]);
		// 	}
		// 	printf("\n");
		// }


		dfs(mapa, 1, flags);
		// printf("Cont = %d\n", cont);
		if (cont == verts-1){
			vector<int> inverso[verts];

			for (int i=0; i<verts; i++){
				for (int k=0; k<mapa[i].size(); k++){
					inverso[mapa[i][k]].push_back(i);
				}
			}
			cont = 0;
			for (int i=0; i<verts; i++){flags[i] = 0;}

			// printf("Grafo inverso:\n");
			// for (int i=0; i<verts; i++){
			// 	printf("%d---> ", i);
			// 	for(int k=0; k<inverso[i].size(); k++){
			// 		printf("%d ", inverso[i][k]);
			// 	}
			// 	printf("\n");
			// }

			dfs(inverso, 1, flags);

			// printf("Segundo cont:%d\n", cont);
			if(cont==verts-1){
				printf("1\n");
			} else{
				printf("0\n");
			}

		} else {
			printf("0\n");
		}
	}

	return 0;
}