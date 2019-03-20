#include <bits/stdc++.h>
#define MAXN 102
#define INF 1e9
using namespace std;

int n;
int matriz[MAXN][MAXN];
int acm[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN];


int soma(int linha, int de, int para){
	if (de == 0) return acm[linha][para];
	return acm[linha][para] - acm[linha][de-1];
}

int solve(int linha, int de, int para){
	if(dp[linha][de][para] != INF) return dp[linha][de][para];
	if (de == para) return dp[linha][de][para] = matriz[linha][para];


	dp[linha][de][para] = soma(linha, de, para);

	int mini = INF;
	int i = de, j = para-1;

	while(j < para+1){
		mini = min(mini, solve(linha-1, i, j));
		i++;
		j++;
	}

	dp[linha][de][para] += mini;

	return dp[linha][de][para];
}

int main(){
	scanf("%d", &n);


	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			scanf("%d", &matriz[i][j]);
			acm[i][j] = matriz[i][j];
			if (j > 0) acm[i][j] += acm[i][j-1];

			for (int z=0; z<n; z++){
				dp[i][j][z] = INF;
			}
		}
	}


	printf("%d\n", solve(n-1, 0, n-1));

	return 0;
}