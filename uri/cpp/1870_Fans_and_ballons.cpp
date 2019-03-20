#include <bits/stdc++.h>

using namespace std;

int col=0, lin=0;
int grid[15][15];

void andar(int start, int linha=0){ //start tem que ser em formato de index
	// printf("start = %d\n", start);
	if (grid[linha][start] != 0){
		printf("BOOM %d %d\n", linha+1, start+1);
		return;
	}

	int left=0, right=0;

	for (int i=start+1; i<col; i++){
		// printf(">>%d\n", grid[linha][i]);
		if (grid[linha][i] != 0) {
			right = i;
			// printf("right = %d\n", right);
			break;
		}
	}

	for (int i=start-1; i>=0; i--){
		if (grid[linha][i] != 0){ 
			left = i;
			// printf("left = %d\n", left);
			break;
		}
	}

	start += grid[linha][left] - grid[linha][right];

	// printf("new start = %d\n", start);

	if (start <= left) {
		printf("BOOM %d %d\n", linha+1, left+1);
		return;
	}

	if (start >= right){
		printf("BOOM %d %d\n", linha+1, right+1);
		return;
	}

	if (linha < lin-1) andar(start, ++linha);
	else printf("OUT %d\n", start+1); 
}

int main(){
	int start, aux;
	memset(grid, 0, sizeof grid);

	while (1){
		scanf("%d %d %d", &lin, &col, &start);

		if (lin == 0 && col == 0 && start == 0) break;

		for (int i=0; i<lin; i++){
			for (int j=0; j<col; j++){
				scanf("%d", &grid[i][j]);
			}
		}

		andar(start-1);

		}

	return 0;
}