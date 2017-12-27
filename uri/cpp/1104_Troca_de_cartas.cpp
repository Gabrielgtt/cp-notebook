#include <bits/stdc++.h>

using namespace std;

int main(){
	int a, b;

	while (scanf("%d %d", &a, &b) && a != 0 && b != 0){
		int aux, setA[100100], setB[100100];
		memset(setA, 0, sizeof setA);
		memset(setB, 0, sizeof setB);

		int numA=0, numB=0;
		for (int i=0; i<a; i++){
			scanf("%d", &aux);
			if (setA[aux] == 0) numA++;
			setA[aux] = 1;
		}

		for (int i=0; i<b; i++){
			scanf("%d", &aux);
			if (setA[aux] == 0 && setB[aux] == 0) numB++;
			if (setA[aux] == 1 && setB[aux] == 0) numA--;
			setB[aux] = 1;
		}

		if (numA < 0) numA = 0;

		printf("%d\n", numA < numB ? numA : numB); 

	}

	return 0;
}