#include <bits/stdc++.h>
using namespace std;

int main(){
	string nome[51], frase;
	int n, maior, dif, notfirst = 0;

	while(scanf("%d", &n) && n != 0){
		if (notfirst) printf("\n");
		notfirst = 1;
		maior = 0;
		cin.ignore();

		for (int i=0; i<n; i++){
			getline(cin, frase);
			if (frase.size() > maior) maior = frase.size();
			nome[i] = frase;
		}

		for (int i=0; i<n; i++){
			dif = maior - nome[i].size(); 
			while(dif--) printf(" ");
			cout << nome[i] << endl;
		}

	}

	return 0;
}