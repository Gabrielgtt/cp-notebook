#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, aDano, aTemp, bDano, bTemp, vida, div, res=1; 

	scanf("%d", &n);

	for (int i=0; i<n; i++){

		scanf("%d %d %d %d", &aDano, &aTemp, &bDano, &bTemp);
		scanf("%d", &vida);

		vida -= aDano;
		if (vida <= 0) {
			printf("Andre\n");

		} else {
			vida -= bDano;

			if (vida <= 0) {
				printf("Beto\n");
			
			} else {

				for (int tempo=1; tempo < 100000; tempo++){
					if (tempo % aTemp == 0){
						res = 0;
						vida -= aDano;
					}

					if (vida <= 0){
						printf("Andre\n");
						break;
					}	

					if (tempo % bTemp == 0){
						res = 1;
						vida -= bDano;
					}

					if (vida <= 0){
						printf("Beto\n");
						break;
					}
				}


			}
		}
	}
}