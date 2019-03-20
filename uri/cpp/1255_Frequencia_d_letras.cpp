#include <bits/stdc++.h>

using namespace std;

int main(){
	string frase;
	int n, maior, freq[130], car;	
	scanf("%d", &n);
	cin.ignore();

	while (n--){
		getline(cin, frase);
		maior = 0;
		memset(freq, 0, sizeof freq);

		for (int i=0; i<frase.size(); i++){
			car = tolower(frase[i]);
			freq[car]++;
			// printf("Freq %c = %d\n", car, freq[car]);
			if (freq[car] > maior && car >= 'a' && car <= 'z') maior = freq[car]; 
		}

		for (int i='a'; i<='z'; i++){
			if (freq[i] == maior) printf("%c", i);
		}
		printf("\n");

	}

	return 0;
}