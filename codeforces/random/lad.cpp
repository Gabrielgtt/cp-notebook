#include <bits/stdc++.h>
#define MAXN 160010
using namespace std;

int matriz[510][510];
int primos[MAXN];

void crivo(){
	primos[1] = 1;
	primos[0] = 1;
	for (int i=2; i<=150000; i++){
		if (primos[i] == 0){
			for (int j = i + i; j <= 150000; j += i){
				primos[j] = 1;
			}			
		}
	}

	for (int i=150000; i>=0; i--){
		if (primos[i] != 0){
			primos[i] += primos[i+1];
		}
	}
}
int colunas[MAXN];
int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	crivo();

	// for (int i=0; i<50; i++){
	// 	printf("%d ", primos[i]);
	// }
	// printf("\n");

	int res = 1e9, aux;
	for (int i=0; i<n; i++){
		aux = 0;
		for (int j=0; j<m; j++){
			scanf("%d", &matriz[i][j]);
			aux += primos[matriz[i][j]];
			colunas[j] += primos[matriz[i][j]];
		}
		if (i == n-1){
			for (int j=0; j<m; j++){
				res = min(colunas[j], res);
			}
		}
		res = min(aux, res);
	}

	printf("%d\n", res);
	return 0;
}