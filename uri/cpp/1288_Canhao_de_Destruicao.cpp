#include <bits/stdc++.h>
# define MAXID 52
# define MAXP 110
using namespace std;
int peso[MAXID], poder[MAXID], bolas;
long long int dp[MAXID][MAXP];

// retorna o maximo de dano que pode ser dado
long long int knapsack(int canhao, int index){
	if (canhao == 0 || index == bolas) return 0;

	if (dp[index][canhao] != -1) return dp[index][canhao];

	if (peso[index] > canhao) return dp[index][canhao] = knapsack(canhao, index+1);

	return dp[index][canhao] = max(knapsack(canhao, index+1), poder[index] + knapsack(canhao-peso[index], index+1)); 
}

int main(){
	int n, vida, canhao;
	long long int danoMax;
	scanf("%d", &n);

	while (n--){
		memset(dp, -1, sizeof dp);
		scanf("%d", &bolas);

		for (int i=0; i<bolas; i++){
			scanf("%d %d", &poder[i], &peso[i]);
		}

		scanf("%d %d", &canhao, &vida);

		danoMax = knapsack(canhao, 0);

		if (danoMax >= vida) printf("Missao completada com sucesso\n");
		else printf("Falha na missao\n");
	}



	return 0;
}