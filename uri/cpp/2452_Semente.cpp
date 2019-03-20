#include <bits/stdc++.h>

using namespace std;


int main(){
	int len, n;

	while (scanf("%d %d", &len, &n) != EOF){
		int a, ant=1, maior=0;

		for (int i=0; i<=n; i++){
			if (i<n) scanf("%d", &a);
			else a = len;

			int dist = a-ant;

			if (i == 0 || i == n){
				if (dist > maior) maior = dist;

			} else if (dist/2 > maior){
				maior = dist/2;
			}

			ant = a;
		}

		printf("%d\n", maior);
	}
	return 0;
}