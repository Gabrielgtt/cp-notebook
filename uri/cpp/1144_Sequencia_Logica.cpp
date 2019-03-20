#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, a=1, b=1, c=1, aux=2;
	scanf("%d", &n);

	for (int i=0; i<n*2; i++){
		printf("%d %d %d\n", a, b, c);

		if (i % 2 == 0){
			b++; c++;
		} else {
			a++;
			b += aux;
			aux += 2;
			c = a*b;
		}

	}
	return 0;
}