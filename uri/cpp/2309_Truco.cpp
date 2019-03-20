#include <bits/stdc++.h>
using namespace std;

// 4 5 6 7 12 11 13 1 2 3
// 1 2 3 4 5  6  7  8 9 10
int main(){
	int n, valor[14];
	valor[4] = 1; 
	valor[5] = 2; 
	valor[6] = 3; 
	valor[7] = 4; 
	valor[12] = 5; 
	valor[11] = 6; 
	valor[13] = 7; 
	valor[1] = 8; 
	valor[2] = 9; 
	valor[3] = 10;

	scanf("%d", &n);

	int rodadaA, rodadaB, cartasA[4], temp, resA, resB;
	resA = 0;
	resB = 0;
	for (int i=0; i<n; i++){
		rodadaA = 0;
		rodadaB = 0;

		scanf("%d %d %d", &cartasA[0], &cartasA[1], &cartasA[2]);

		for (int i=0; i<3; i++){
			scanf("%d", &temp);
			if (valor[temp] > valor[cartasA[i]]){
				rodadaB++;
			} else {
				rodadaA++;
			}
		}

		if (rodadaA > rodadaB) resA++;
		else resB++; 
	}

	printf("%d %d\n", resA, resB);

	return 0;
}