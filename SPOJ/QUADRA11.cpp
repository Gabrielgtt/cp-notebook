#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;

int main(){
	int matriz[MAXN][MAXN];
	int n, soma;
	scanf("%d %d", &n, &soma);

	if (n == 1){
		printf("%d\n", soma);
		return 0;
	}

	int magico = 0, aux = n;
	for (int i=0; i<n-1; i++){
		magico += aux;
		aux += n - 1;
		// printf("magico = %d\n", magico);
	}
	magico = soma - magico;
	// printf("magico = %d\n", magico);

	aux = 1;
	for (int i=0; i<n-1; i++){
		for (int j=0; j<n; j++){
			if (j != 0) printf(" ");
			printf("%d", aux++);
		}
		printf("\n");
	}

	for (int i=0; i<n; i++){
		if (i != 0) printf(" ");
		printf("%d", magico++);
	}

	printf("\n");
		

	return 0;
}