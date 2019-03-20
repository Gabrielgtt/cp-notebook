#include <bits/stdc++.h>

using namespace std;

int main(){
	string frase;
	int aliterando, res;
	char ant;

	while (getline(cin, frase)){
		res = aliterando = 0;

		for (int i=0; i<frase.size(); i++){
		
			if (i == 0) ant = tolower(frase[i]);
			else{
				if (frase[i-1] == ' '){
					if (tolower(frase[i]) == ant && !aliterando){
						res++, aliterando = 1;
					} else if (tolower(frase[i]) != ant) {
						ant = tolower(frase[i]), aliterando = 0;
					}
				}
			}

		}

		printf("%d\n", res);

	}


	return 0;
}