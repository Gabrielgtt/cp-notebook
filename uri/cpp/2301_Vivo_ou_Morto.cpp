#include <bits/stdc++.h>
using namespace std;

int main(){
	int rods, pes, posicao[110], morto[110], numRodada = 1, jogs, ordem, mov, prox, aux;

	while (true){
		scanf("%d %d", &pes, &rods);
		if (pes == 0 && rods == 0) break;
		else printf("Teste %d\n", numRodada++);

		memset(morto, 0, sizeof morto);

		for (int i=1; i<=pes; i++){
			scanf("%d", &aux);
			posicao[i] = aux;
		}

		for (int i=0; i<rods; i++){
			scanf("%d %d", &jogs, &ordem);
			prox = 1;
			for (int j=1; j<=jogs; j++){
				scanf("%d", &mov);

				while (morto[prox] == 1) prox++;
				if (mov != ordem) morto[prox] = 1;
				prox++;
			}
		}

		prox = 1;
		while (morto[prox] == 1) prox++;
		printf("%d\n\n", posicao[prox]);
	}

	return 0;
}