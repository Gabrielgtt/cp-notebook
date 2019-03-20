#include <bits/stdc++.h>

using namespace std;

int max(int a, int b){return (a > b) ? a : b;}

int knapsack(int cap_galho, int n, int enfeite[], int peso[]){
	if (n == 0 || cap_galho == 0){
		return 0;
	}

	if (peso[n-1] > cap_galho){
		return knapsack(cap_galho, n-1, enfeite, peso);
	}

	return max(enfeite[n-1] + knapsack(cap_galho-peso[n-1], n-1, enfeite, peso), knapsack(cap_galho, n-1, enfeite, peso));
}

int main(){
	int num_galhos;
	scanf("%d", &num_galhos);

	for (int galho=1; galho <= num_galhos; galho++){

		int num_c, cap_galho;
		scanf("%d %d", &num_c, &cap_galho);

		int enfeite[num_c], peso[num_c]; 
		for (int i=0; i<num_c; i++){
			scanf("%d %d", &enfeite[i], &peso[i]);
		}

		printf("Galho %d:\n", galho);
		printf("Numero total de enfeites: %d\n\n", knapsack(cap_galho, num_c, enfeite, peso));
	}

	return 0;
}