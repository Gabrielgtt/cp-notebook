#include <bits/stdc++.h>
#define MAXN 10010
#define MOD 1000000000
#define rep(i, a, b) for(int(i)=(a);(i)<(b);(i)++)
#define swap(a, b) a = b + a - (b = a)
using namespace std;

int flags[MAXN];

int colorDfs(vector<int> grafo[], int index, int ant){
	// printf("Atual = %d\n", index);
	int res=0;
	flags[index] = 1;

	for (int i=0; i<grafo[index].size(); i++){
		// printf("prox = %d flag dele = %d\n", grafo[index][i], flags[grafo[index][i]]);
		if (grafo[index][i] != ant){
			if (flags[grafo[index][i]] == 1) {
				// printf("Ciclo achado em %d\n", grafo[index][i]);
				return 1;
			}
			else res += colorDfs(grafo, grafo[index][i], index);
		}
	}
	
	return res;
}

int main(){
	int cits, roads, de, para;
	while (scanf("%d %d", &cits, &roads) != EOF){
		memset(flags, 0, sizeof flags);
		vector<int> grafo[MAXN];


		for (int i=0; i<roads; i++){
			scanf("%d %d", &de, &para);
			grafo[de].push_back(para);
			grafo[para].push_back(de);
		}

		para = 0;
		for (int i=1; i<=cits; i++){
			if (flags[i] == 0) {
				if (colorDfs(grafo, i, 0)){
					para = 1;
					break;
				}
			}
		}

		if (para) printf("Inseguro\n");
		else printf("Seguro\n");

		// printf("\n");
	}

	return 0;
}