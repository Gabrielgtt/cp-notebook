#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	pair<int, int> micro, ini;
	ini.first = 0; ini.second = 0;
	scanf("%d %d", &micro.first, &micro.second);

	int moves, to, res=0, difH, difV;
	scanf("%d", &moves);


	for (int i=0; i<moves; i++){


		scanf("%d", &to);

		printf("Estou em <%d, %d>\n", ini.first, ini.second);
		printf("Indo para %d\n", to);

		if (to == 2){
			if (ini.first-1 >= 0){
			ini.first -= 1;
			}
		} else if (to == 1) {
			if (ini.first+1 < n){
				ini.first += 1;
			}
		} else if (to == 3) {
			if (ini.second+1 < m){
				ini.second += 1;
			}
		} else {
			if (ini.second-1 >= 0){
				ini.second -= 1;
			}
		}

		for (int linha=0; linha<n; linha++){
			for (int col=0; col<m; col++){

				if (linha == micro.first && col == micro.second){
					printf("M ");
				} else if (linha == ini.first && col == ini.second){ 
					printf("B ");
				} else { printf(". ");}
			}
			printf("\n");
		}

		difH = abs(micro.first - ini.first);
		difV = abs(micro.second - ini.second);
		if (difH <= 1 && 0 <= difH && 0 <= difV && difV <= 1){
			res++;
		}
		 	
	}

	printf("%d\n", res);

	return 0;
}