#include <bits/stdc++.h>

using namespace std;

int main(){
	string frase;
	int flip;

	while (getline(cin, frase)){
		flip = 1;

		for(int i=0; i<frase.size(); i++){

			if (flip){
				printf("%c", toupper(frase[i]));
			} else {
				printf("%c", tolower(frase[i]));				
			}

			if (frase[i] != ' ') flip = !flip;
		}

		printf("\n");

	}



	return 0;
}