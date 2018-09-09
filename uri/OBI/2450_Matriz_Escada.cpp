#include <bits/stdc++.h>
#define MAXN 540
using namespace std;

int matriz[MAXN][MAXN], n, m;

bool opa(int i, int j){

	for (int r=i+1; r<n; r++){
		for (int c=0; c<=j; c++){
			if (matriz[r][c]){
				return true;
			}
		}
	}
	return false;
}

int main(){
	scanf("%d %d", &n, &m);

	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			scanf("%d", &matriz[i][j]);
		}
	}

	for (int i=0; i<n; i++){
		int check = 0;
		for (int j=0; j<m; j++){
			check += matriz[i][j];
			if (matriz[i][j] != 0){
				if (opa(i, j)){
					// printf("if1 no %d %d\n", i, j);
					printf("N\n");
					return 0;
				}
				break;
			}
		}
		if (check == 0){
			for (int r=i+1; r<n; r++){
				for (int c=0; c<m; c++){
					if (matriz[r][c]){
						// printf("if2 no %d %d\n", r, c);
						printf("N\n");
						return 0;
					}
				}
			}
			break;
		}
	}


	printf("S\n");
	return 0;
}