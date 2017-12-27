#include <bits/stdc++.h>

using namespace std;


int main(){
	int	lin, col, inst;

	while (scanf("%d %d %d", &lin, &col, &inst) && lin != 0){
		char grid[lin][col];

		int lnow, cnow, res=0;
		char dir, coluna[col-1];
		for (int i=0; i<lin; i++){
			cin >> coluna;
			for (int j=0; j<col; j++) {
				grid[i][j] = coluna[j]; 			
			
				if (coluna[j] != '.' && coluna[j] != '*' && coluna[j] != '#'){
					lnow = i; cnow = j; dir = grid[i][j];
				}
			}
		}

		char com[inst-1];
		cin >> com;
		for (int i=0; i<inst; i++){
			int l = lnow, c = cnow;
			if (com[i] == 'F'){ 
				if (dir == 'N') l--;
				else if (dir == 'S') l++;
				else if (dir == 'L') c++;
				else if (dir == 'O') c--;

				if (l < lin && l >= 0 && c < col && c >= 0){
					if (grid[l][c] != '#'){
						grid[lnow][cnow] = '.';
						lnow = l; cnow = c;
						if (grid[l][c] == '*') res++;
					}
				}

			} else if (com[i] == 'E'){
				if (dir == 'N'){
					dir = 'O';			
				} else if (dir == 'O'){
					dir = 'S';			
				} else if (dir == 'S'){
					dir = 'L';			
				} else {dir = 'N';}	

			} else {
				if (dir == 'N') {
					dir = 'L';			
				} else if (dir == 'L'){
					dir = 'S';			
				} else if (dir == 'S'){
					dir = 'O';			
				} else {dir = 'N';}	
			}

			grid[lnow][cnow] = dir;

		}

		printf("%d\n", res);

	}



	return 0;
}