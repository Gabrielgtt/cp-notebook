#include <bits/stdc++.h>

using namespace std;

int max (int a, int b) { return (a > b) ? a : b;}


int knapsack(int cap_mochila, int n, int peso[], int ponto[]){
	int pontos_otimo[cap_mochila+1];
	memset(pontos_otimo, 0, sizeof pontos_otimo);

	for (int hora = 0; hora <= cap_mochila; hora++){ // Pra cada capacidade de mochila

    	for (int j=0; j<n; j++){ // Pra cada livro

        	if (peso[j] <= hora) { // Testo se colocar esse livro é melhor do que já está
	       		pontos_otimo[hora] = max(pontos_otimo[hora], pontos_otimo[hora - peso[j]] + ponto[j]);
	       	}
         }

	}

	return pontos_otimo[cap_mochila];
}


int main(){
	int n, tempo, aux = 1;

	while (1){
		scanf("%d %d", &n, &tempo);
		if (n == 0 && tempo == 0) break;

		int peso[n], ponto[n];

		for (int i=0; i<n; i++){
			scanf("%d %d", &peso[i], &ponto[i]);
		}

		printf("Instancia %d\n", aux); aux++;
		printf("%d\n\n", knapsack(tempo, n, peso, ponto));
	}

	return 0;
}