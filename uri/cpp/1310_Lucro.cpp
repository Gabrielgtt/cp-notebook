#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, custo, array[51], maxTotal, maxHere;

	while (scanf("%d", &n) != EOF){
		scanf("%d", &custo);

		maxHere = 0;
		maxTotal = 0;

		for (int i=0; i<n; i++){
			scanf("%d", &array[i]);
			array[i] -= custo;

			maxHere += array[i];

			if (maxTotal < maxHere) maxTotal = maxHere;

			if (maxHere < 0) maxHere = 0;
		}

		printf("%d\n", maxTotal);
	}

	return 0;
}