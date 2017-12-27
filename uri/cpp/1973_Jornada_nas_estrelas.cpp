#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; scanf("%d", &n);

	int aux, uns=0, flag = 1, vis=n;
	long long soma=0, total=0;
	for (int i=0; i<n; i++){
		scanf("%d", &aux);
		total += aux;

		if (aux & 1) {
			// printf("%d ONe\n", aux);
			if (aux == 1) uns++;
			if (flag) soma++;
		} else if (flag) {
			// printf("%d TWo\n", aux);
			if (aux != 0) soma++;
			vis = i+1;
			soma += i - uns;
			flag = 0;
		}
	}

	printf("%d %llu\n", vis, total-soma);
}