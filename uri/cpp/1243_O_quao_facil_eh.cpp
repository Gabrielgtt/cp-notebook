#include <bits/stdc++.h>
using namespace std;

int isLetra(char l){
	if ((l >= 'a' && l <= 'z') || (l >= 'A' && l <= 'Z')) return 1;
	return 0;  
}

int isNum(char l){
	if (l >= '0' && l <= '9') return 1;
	return 0;
}

int main(){
	string frase;
	char letra;
	int start, media, numPalavras, len, valida, segundo;
	// cin.ignore();
	
	while (getline(cin, frase)){
		// cout << frase << endl;
		// cout << "TESTES" << endl;
		start = media = numPalavras = len = segundo = 0;
		valida = 1;
		
		for (int i=0; i<frase.size(); i++){
			letra = frase[i];

			if (letra != ' '){
				start = 1;

				if (isLetra(letra)){
					if (segundo) valida = 0;
					if (valida) len++;

				} else if (isNum(letra)){
					valida = 0;

				} else if (letra == '.'){
					if (segundo) valida = 0;
					else segundo = 1;
				}

			} else {			
				if (valida && start) media += len, numPalavras += len > 0 ? 1 : 0;
				valida = 1;
				start = 0;
				segundo = 0;
				len = 0;
			}
		}

		if (valida && start) media += len, numPalavras++;

		if (numPalavras == 0) media = 0;
		else media /= numPalavras; 

		// printf("Num palavras = %d\nMedia = %d\n", numPalavras, media);

		if (media <= 3) printf("250\n");
		else if (media < 6) printf("500\n");
		else printf("1000\n");
	}

	return 0;
}