#include <bits/stdc++.h>
	
using namespace std;

int main(){
	string dieta, cafe, almoco;
	int n, log[130], cheat=0;
	scanf("%d", &n);
	cin.ignore();

	while (n--){
		memset(log, 0, sizeof log);
		getline(cin, dieta);
		getline(cin, cafe);
		getline(cin, almoco);
		cheat = 0;

		for (int i=0; i<dieta.size(); i++){
			log[dieta[i]] = 1;
		}
		for (int i=0; i<cafe.size(); i++){
			if (log[cafe[i]] == 0) cheat = 1;
			log[cafe[i]] = 2;
		}
		for (int i=0; i<almoco.size(); i++){
			if (log[almoco[i]] == 0) cheat = 1;
			log[almoco[i]] = 2;
		}

		if (cheat){
			printf("CHEATER\n");
		} else {
			for (int i='A'; i<='Z'; i++){
				if (log[i] == 1) printf("%c", i);
			}
			printf("\n");
		}



	}

	return 0;
}