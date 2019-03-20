#include <bits/stdc++.h>
#define repeat(a, b, c) for (int i = int(a); i<int(b); i+=int(c))

using namespace std;

int flags[501];

int menor(int idade[], int a, int b){
	return idade[a] < idade[b] ? a : b;
}	

int dfs(vector <int> grafo[], int chefe[], int idade[], int start){
	flags[start] = 1;

	if (chefe[start] == start) return start;

	repeat(0, grafo[start].size(), 1){

		if (flags[grafo[start][i]] == 0){
			chefe[start] = menor(idade, idade[start], dfs(grafo, chefe, idade, i));
		}
	}

	return chefe[start];
}

void trade(int chefe[], int idade[], int a, int b){
	int aux = chefe[a];
	chefe[a] = chefe[b]; chefe[b] = aux;
	aux = idade[a];
	idade[a] = idade[b]; idade[b] = aux;

}


int main(){
	int num, con, quest; 

	while (scanf("%d %d %d", &num, &con, &quest) != EOF){

		int idade[num+1], chefe[num+1];

		repeat(1, num+1, 1) chefe[i] = i;

		repeat(1, num+1, 1){
			scanf("%d", &idade[i]);
		}

		vector <int> grafo[num+1];
		int a, b;

		repeat(0, con, 1) {
			scanf("%d %d", &a, &b);
			grafo[b].push_back(a);

			if (idade[chefe[a]] < idade[chefe[b]] || chefe[b] == b){
				chefe[b] = chefe[a];
			}
		}

		char q;
		repeat(0, quest, 1){
			scanf("%s", &q);

			if (q == 'P') { 
				scanf("%d", &a);
				memset(flags, 0, sizeof flags);
				printf("%d\n", idade[dfs(grafo, chefe, idade, a)]);
			} else {
				scanf("%d %d", &a, &b);
				trade(chefe, idade, a, b);
			}
		}



	}


	return 0;
}