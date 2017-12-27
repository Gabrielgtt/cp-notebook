#include <bits/stdc++.h>
#define MAXN 1000010
#define ull unsigned long long int
using namespace std;

int raiz, casos, querys, n;

// 3 arrays:
// grupos[i] mostra a soma total dos elementos no i
// somaG[i] mostra a soma total dos updates que aquele grupo i recebeu
// arr[i] mostra a soma total dos updates individuais que i recebeu.
// Posso atualizar todos os elementos de um grupo i somando 
// a quantidade value em somaG[i].
// Tbm posso obter o valor de um indice i somando:
// arr[i] + somaG[i] = adições individuais + adições feitas a todos do grupo

ull grupos[1010], somaG[1010], despair[1010], arr[MAXN]; 

void update(int l, int r, int value){
	int div;
	for (int i=l; i<=r; i++){
		div = i/raiz; // Tentando reduziro número de divisões
		if (i % raiz == 0 && i + raiz - 1 <= r){
			grupos[div] += value;
			somaG[div] += value;
			i += raiz-1;
		} else {
			despair[div] += value;
			arr[i] += value;
		}
	}
}

ull getSum(int l, int r){
	ull res = 0;
	int div; 
	for (int i=l; i<=r; i++){
		div = i/raiz;
		if (i % raiz == 0 && i + raiz - 1 <= r){
			res += grupos[div]*raiz + despair[div];
			i += raiz-1;
		} else {
			res += arr[i] + somaG[div];
		}
	}
	return res;
}

int main(){
	scanf("%d", &casos);

	while (casos--){
		scanf("%d %d", &n, &querys);
		memset(grupos, 0, sizeof grupos);
		memset(somaG, 0, sizeof somaG);
		memset(despair, 0, sizeof despair);
		memset(arr, 0, sizeof arr);

		raiz = (int) sqrt(n +.0)+1;
		// printf(">>%d\n\n", raiz);

		int tipo, i, j, val;
		while (querys--){
			scanf("%d", &tipo);

			if (tipo == 1){
				scanf("%d %d", &i, &j);i--;j--;
				cout << getSum(i, j) << endl;
			} else {
				scanf("%d %d %d", &i, &j, &val);i--;j--;
				update(i, j, val);
			}
		}
	}	

	return 0;
}