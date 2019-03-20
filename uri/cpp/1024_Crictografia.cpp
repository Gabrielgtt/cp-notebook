#include <bits/stdc++.h>
using namespace std;

int main(){
	string array; 2
	char letra;
	int n, lim, len, cont, aux;
	scanf("%d", &n);
	cin.ignore();

	for (int i=0; i<n; i++){
		getline(cin, array);
		len = array.size();
		lim = (len >> 1) + (len & 1);
		cont = len-1; 

		for (string::reverse_iterator it = array.rbegin(); it != array.rend(); it++){
			letra = *it;
			aux = 0;
		
			if ((65 <= letra && letra <= 90) || (97 <= letra && letra <= 122)){
				aux += 3;
			}

			if (cont < lim){
				aux--;
			} 

			printf("%c", letra + aux);
			cont--;
			
		}
		printf("\n");

	}


	return 0;
}