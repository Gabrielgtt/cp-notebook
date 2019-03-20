#include <bits/stdc++.h>
#define MAXN 2000010
using namespace std;

int playersA[MAXN], playersB[MAXN], temp[MAXN];
int aux, numPessoas, eventos, limite;

struct Status{
	int bola, valido;
	int placar[2];
	char posse;
} Jogo;

void updateBIT(int BITree[], int index, int valor){
	index += 1;

	while (index <= MAXN){
		BITree[index] += valor;
		index += index & (-index);		
	}
}

int getSum(int BITree[], int index){
	int sum = 0;
	index += 1;

	while (index > 0){
		sum += BITree[index];
		index -= index & (-index); 
	}

	return sum;
}

int *constructBITree(int array[]){
	int *BITree = new int[MAXN+1];

	for (int i=0; i<MAXN; i++)
		updateBIT(BITree, i, array[i]);

	return BITree;
}

void moverPlayer(int campo[], int jogador, int final, int players[]){
	updateBIT(campo, players[jogador], -1);
	updateBIT(campo, final, 1);	

	players[jogador] = final;
}

void checkImp(int campoA[], int campoB[]){
	if (Jogo.posse == 'A'){
		// printf("Checando impedimento:\n>> Limite = %d e Jogadores = %d\n", limite, getSum(campoB, MAXN) - getSum(campoB, playersA[Jogo.bola]));
		if (limite > (getSum(campoB, MAXN) - getSum(campoB, playersA[Jogo.bola]))) Jogo.valido = 0;
		// printf("Validade = %d\n", Jogo.valido);
	} else{
		// printf("Checando impedimento:\n>> Limite = %d e Jogadores = %d\n", limite, getSum(campoA, playersB[Jogo.bola]-1));
		if (limite > getSum(campoA, playersB[Jogo.bola]-1)) Jogo.valido = 0;
		// printf("Validade = %d\n", Jogo.valido);
	}
}


int main(){

	while (scanf("%d %d", &numPessoas, &eventos) && numPessoas != 0){
		
		limite = ceil(numPessoas/11.0);

		memset(temp, 0, sizeof temp);
		for (int i=0; i<numPessoas/2; i++){
			scanf("%d", &playersA[i]);
			temp[playersA[i]]++;
	 	}
	 	int *campoA = constructBITree(temp);

		memset(temp, 0, sizeof temp);
		for (int i=0; i<numPessoas/2; i++){
			scanf("%d", &playersB[i]);
			temp[playersB[i]]++;
	 	}
	 	int *campoB = constructBITree(temp);


		Jogo.valido = 1;
		Jogo.placar[0] = 0;
		Jogo.placar[1] = 0;
	 	char tipo, time;
	 	int jogador, pos, golsA=0, golsB=0;

	 	for (int i=0; i<eventos; i++){
	 		cin >> tipo;

	 		if (tipo == 'I'){
	 			cin >> Jogo.posse >> Jogo.bola;
	 			Jogo.bola--;
	 			// printf("Jogador %d do time %c recebeu a bola do juiz\n", Jogo.bola, Jogo.posse);
				checkImp(campoA, campoB); 			

	  		} else if (tipo == 'M') {
	 			cin >> time >> jogador >> pos;
	 			jogador--;
	 			// printf("Jogador %d do time %c se moveu para %d\n", jogador, time, pos);

				if (time == 'A') moverPlayer(campoA, jogador, pos, playersA);  			
				else moverPlayer(campoB, jogador, pos, playersB);

	  		} else if (tipo == 'P'){
	 			cin >> Jogo.posse >> Jogo.bola;
	 			Jogo.bola--;
	 			// printf("Jogador %d do time %c recebeu a bola\n", Jogo.bola, Jogo.posse);
				checkImp(campoA, campoB); 			

	  		} else if (tipo == 'G'){
	  			cin >> time;
	  			// printf("Gol de validade %d no time %c\n", Jogo.valido, time);
	  			if (Jogo.valido) {
	  				if (time == 'A') Jogo.placar[1]++;
	  				else Jogo.placar[0]++;
	  			}

	  			Jogo.valido = 1;


	  		} else if (tipo == 'S'){
	  			// printf("A bola saiu\n");
	  			Jogo.valido = 1;
	  		}
	 	}

	 	printf("%d X %d\n", Jogo.placar[0], Jogo.placar[1]);
	 	// printf("\n\n");
	}
 	
 	return 0;
}