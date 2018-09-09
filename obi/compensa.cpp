#include <bits/stdc++.h>
#define MAXN 1000010
#define ii pair <int, int>
using namespace std;

int n, m;
int custoOriginal = 0, custoReduzido = 0;
int saldo[MAXN];


int main(){
	scanf("%d %d", &m, &n);

	int custo, de, para;
	for (int i=0; i<m; i++){
		scanf("%d %d %d", &de, &custo, &para);
		saldo[de] -= custo;
		saldo[para] += custo;
		custoOriginal += custo;
	}

	for (int i=1; i<=n; i++) if(saldo[i] > 0) custoReduzido += saldo[i];
	// for (int i=1; i<=n; i++) printf("%d = %d\n", i, saldo[i]);

	if (custoOriginal != custoReduzido){
		printf("S\n");
		printf("%d\n", custoReduzido);
	} else {	
		printf("N\n");
		printf("%d\n", custoOriginal);
	}

	return 0;
}
