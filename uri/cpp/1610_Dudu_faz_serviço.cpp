#include <bits/stdc++.h>

using namespace std;

int dfs(vector<int> grafo[], int cor[], int start){
	//Pintando de cinza o que for branco
	if (cor[start] == 1) return 1;

	if (cor[start] == -1) return 0;

	cor[start] = -1;

	for (int prox=0; prox < grafo[start].size(); prox++){

		if (dfs(grafo, cor, grafo[start][prox]) == 0){
			return 0;
		}
	}
	
	cor[start] = 1;
	return 1;

}


int main(){
	int T;
	scanf("%d", &T);

	for (int caso = 1; caso <= T; caso++){
		int verts, edges;
		scanf("%d %d", &verts, &edges);

		vector<int> grafo[verts+1];

		int de, para;
		for (int i=1; i<=edges; i++){
			scanf("%d %d", &de, &para);
			grafo[de].push_back(para);
		}

		int cor[verts+1], flags = 1;
		memset(cor, 0, sizeof cor);

		for (int vert = 1; vert <= verts; vert++){

			if (cor[vert] == 0) {

				if (dfs(grafo, cor, vert) == 0){
					flags = 0;
					printf("SIM\n");
					break;
				}
			}
		}

		if (flags) printf("NAO\n");


	}

	return 0;
}
