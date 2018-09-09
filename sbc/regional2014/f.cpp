#include <bits/stdc++.h>
#define ll long long
#define MAXN 101
#define MOD 10000
using namespace std;

int n, l, source, to, matriz[MAXN][MAXN], base[MAXN][MAXN], res[MAXN][MAXN];

void multBase(){
	for (int linha=0; linha<n; linha++){
		for (int coluna=0; coluna<n; coluna++){
			int soma = 0;
			for (int i=0; i<n; i++){
				soma += ((matriz[linha][i] % MOD) * (base[i][coluna] % MOD)) % MOD;
				soma %= MOD;
			}
			res[linha][coluna] = soma;
		}
	}
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			matriz[i][j] = res[i][j];
		}
	}
}

void multSelf(){
	for (int linha=0; linha<n; linha++){
		for (int coluna=0; coluna<n; coluna++){
			int soma = 0;
			for (int i=0; i<n; i++){
				soma += ((matriz[linha][i] % MOD) * (matriz[i][coluna] % MOD)) % MOD;
				soma %= MOD;
			}
			res[linha][coluna] = soma;
		}
	}
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			matriz[i][j] = res[i][j];
		}
	}
}

void fastExpo(int e){
	if (e == 1 || e == 0) return;

	fastExpo(e >> 1);

	multSelf();

	if (e & 1)	multBase();
}

int main(){

	while (scanf("%d %d", &n, &l) != EOF){
		memset(matriz, 0, sizeof matriz);
		memset(base, 0, sizeof base);
		scanf("%d %d", &source, &to);
		int aux;
		for (int i=0; i<n; i++){
			for (int j=0; j<4; j++){
				scanf("%d", &aux);
				aux--;
				matriz[i][aux]++;
				base[i][aux]++;
			}
		}
		if (l == 0){
			if (source == to) printf("1\n");
			else printf("0\n");
		} else {
			fastExpo(l);
			printf("%d\n", matriz[source-1][to-1]);
			
		}
	}

	return 0;
}