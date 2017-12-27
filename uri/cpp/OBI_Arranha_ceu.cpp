#include <bits/stdc++.h>
using namespace std;

void updateBIT(int BITree[], int n, int index, int val){
	// Index na BIT é 1+ do que no array original
	index += 1;

	// "n" é o tamanho do array original
	while (index <= n){
		BITree[index] += val;
		index += index & (-index);	
	}
}

int getSum(int BITree[], int index){
	int sum = 0;
	index += 1;

	while (index>0){
		sum += BITree[index];
		index -= index & (-index);
	}
	return sum;
}

// Constroi a BIT a partir de um array de ints 
// de tamanho n. Usa a funcao updateBIT
int *constructBIT(int array[], int n){
	int *BITree = new int[n+1];

	for (int i=0; i<n; i++)
		updateBIT(BITree, n, i, array[i]);

	return BITree;
}

int main(){
	int n, Qs;
	scanf("%d %d", &n, &Qs);
	int array[n];

	for (int i=0; i<n; i++)
		scanf("%d", &array[i]);

	int *BITree = constructBIT(array, n);

	int tipo, A, B, dif;
	while (Qs--){
		scanf("%d", &tipo);

		if (tipo){
			scanf("%d", &A);
			printf("%d\n", getSum(BITree, A-1));
		} else {
			scanf("%d %d", &A, &B);
			dif = B - array[A-1];
			// printf("De %d para ", array[A-1]);
			array[A-1] = B;
			updateBIT(BITree, n, A-1, dif);
			// printf("%d\n", array[A-1]);
		}

	}

	return 0;
}