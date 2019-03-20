#include <bits/stdc++.h>
#define MAXN 1000010
#define ii pair <int, int >
using namespace std;

int main(){
	int n, aux=1, cons[500];
	ii dados[MAXN];

	while (scanf("%d", &n) && n!=0){
		float soma=0, div=0;

		memset(cons, 0, sizeof cons);

		for (int i=0; i<n; i++){
			scanf("%d %d", &dados[i].second, &dados[i].first);
			soma += dados[i].first;
			div += dados[i].second;
			dados[i].first /= dados[i].second;
			cons[dados[i].first] += dados[i].second;
		}

		if (aux != 1) printf("\n");
		printf("Cidade# %d:\n", aux); aux++;
		sort(dados, dados+n);

		for (int i=0; i<n; i++){
			if (cons[dados[i].first] != -1){
				dados[i].second = cons[dados[i].first];
				cons[dados[i].first] = -1;
				printf("%d-%d", dados[i].second, dados[i].first);
				if (i != n-1) printf(" ");
			}
		}

		float res = floor((soma/div)*100)/100.0;
		printf("\nConsumo medio: %.2f m3.\n", res);
	}


	return 0;
}