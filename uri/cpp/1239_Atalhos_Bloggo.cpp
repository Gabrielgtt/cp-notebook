#include <bits/stdc++.h>
using namespace std;

int main(){
	string frase;
	int ita, neg;

	while (getline(cin, frase)){
		ita = neg = 0;

		for (int i=0; i<frase.size(); i++){
			if (frase[i] == '_'){
				if (ita){
					printf("</i>");
					ita = !ita;
				} else {
					printf("<i>");
					ita = !ita;
				}
			} else if (frase[i] == '*'){
				if (neg){
					printf("</b>");
					neg = !neg;
				} else {
					printf("<b>");
					neg = !neg;
				}
			} else {
				printf("%c", frase[i]);
			}
		}

		printf("\n");
	}

}