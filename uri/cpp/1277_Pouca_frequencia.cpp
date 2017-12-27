#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, num, printed, media, pres;
	string nomes[110], nota; 
	scanf("%d", &n);

	while (n--){
		scanf("%d", &num);

		for (int i = 0; i < num; i++){
			cin >> nomes[i];
		}

		printed = 0;
		for (int i = 0; i < num; i++){
			cin >> nota;
			media = 0;
			pres = 0;

			for (int j=0; j<nota.size(); j++){
				if (nota[j] != 'M') media++;
			}
			// printf("|%d|", media);

			media = ceil(0.75 * media);
			
			// printf("|%d|", media);

			for (int j=0; j<nota.size(); j++){
				if (nota[j] == 'P') pres++;
			}

			if (pres < media){ 
				if (printed) printf(" ");
				cout << nomes[i];
				printed = 1;
			}
			if (i == num-1) printf("\n");
		}
	}


	return 0;
}