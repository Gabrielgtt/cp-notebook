#include <bits/stdc++.h>

#define MAXN 1001010

using namespace std;

int chocolates=0, jogada_maxima=0;
int posicao[MAXN], proibidos[MAXN];

int jogadas(){
	for (int i=0; i<=chocolates; i++) posicao[i] = proibidos[i] = 0;

	for (int i=0; i<=chocolates; i++){

		if (posicao[i] == 0) {

			for (int j=1; j<=jogada_maxima; j++){
				posicao[i+j]++;
				proibidos[i+j] = j;
			}

		} else if (posicao[i] == 1 && i + proibidos[i] <= chocolates) {
			posicao[i + proibidos[i]] ++;
			proibidos[i + proibidos[i]] = proibidos[i];
		}
	}

	return posicao[chocolates];
}


int main(){
	scanf("%d %d", &chocolates, &jogada_maxima);

	printf("%s\n", jogadas() ? "Paula" : "Carlos");
	return 0;
}