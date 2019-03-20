#include <bits/stdc++.h>

using namespace std;

int main (){
	int num, pos=0, neg=0, par=0, imp=0;

	for (int i=0; i<5; i++){
		scanf("%d", &num);
		
		if (num < 0){
			neg++;
		} else if (num != 0){
			pos++;
		}

		if (num % 2 == 0){
			par++;
		} else {
			imp++;
		}
	}

	printf("%d valor(es) par(es)\n", par);
	printf("%d valor(es) impar(es)\n", imp);
	printf("%d valor(es) positivo(s)\n", pos);
	printf("%d valor(es) negativo(s)\n", neg);

	return 0;
}