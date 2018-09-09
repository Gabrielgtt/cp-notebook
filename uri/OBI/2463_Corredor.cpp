#include <bits/stdc++.h>
#define MAXN 60000
using namespace std;

int main(){
	int n, aux;

	scanf("%d", &n);

	int maior, hope = 0;
	for (int i=0; i<n; i++){
		scanf("%d", &aux);

		if (i == 0) maior = aux, aux > 0 ? hope = aux : hope = 0;
		else {
			if (aux >= 0){
				hope += aux;
				maior = max(hope, maior);
			} else {
				if (hope + aux >= 0){
					hope += aux;
				} else {
					hope = 0;
				}
			}
		}
		// printf("%d %d\n", maior, hope);
		maior = max(maior, aux);
	}

	printf("%d\n", maior);

	return 0;
}