#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	map <int, int> bag;
	map <int, int>::iterator it;

	int freq = -1, numero;
	for (int i=0; i<n; i++){
		scanf("%d", &numero);
		bag[numero]++;
	}

	for (it = bag.begin(); it != bag.end(); it++){
		pair <int, int> atual = *it;
		if (atual.second > freq){
			freq = atual.second;
			numero = atual.first;
		} else if (atual.second == freq && atual.first > numero){
			numero = atual.first;
		}
	}

	printf("%d\n", numero);
	return 0;
}