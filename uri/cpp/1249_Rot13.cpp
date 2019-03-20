#include <bits/stdc++.h>

using namespace std;

int main(){
	string frase;
	while(getline(cin, frase)){
		for (int i=0; i<frase.size(); i++){
			if (frase[i] >= 'a' && frase[i] <= 'z'){
				printf("%c", (frase[i]-'a'+13)%26 + 'a');
			} else if (frase[i] >= 'A' && frase[i] <= 'Z'){
				printf("%c", (frase[i]-'A'+13)%26 + 'A');
			} else {
				printf("%c", frase[i]);
			}
		}
		printf("\n");
	}
}