#include <bits/stdc++.h>
using namespace std;


int main(){
	string num;
	int lenStr, lim, zeroEsq, aux, ant, index;
	char maior;

	while ((cin >> lenStr >> lim) && lim > 0){
		int aaa = lenStr-lim;
		ant = -1;
		zeroEsq = index = 0;
		lenStr--;
		cin >> num;

		for (int j=0; j < aaa; j++){
			maior = '0'-1;

			// printf("--");
			for (int i=lim; i > ant; i--){
				if (num[i] >= maior) maior = num[i], index = i;
				// printf("%d-", i);
			}
			// printf("-\n");
			// printf("index = %d\n",index );

			if (maior == '0'){
				if (zeroEsq) printf("%c", maior);
			} else {
				printf("%c", maior);
				zeroEsq = 1;
			}

			ant = index;
			lim++; 
		}

		printf("\n");
	}



	return 0;
}