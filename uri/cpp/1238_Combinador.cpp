#include <bits/stdc++.h>

using namespace std;

int main(){
	string s1, s2;
	int maior, n, aux, len1, len2;
	scanf("%d", &n);

	while (n--){
		cin >> s1 >> s2;
		aux = 0;
		len1 = s1.size();
		len2 = s2.size();
		maior = max(len1, len2);
		
		while (maior--){
			if (aux < len1) printf("%c", s1[aux]);
			if (aux < len2) printf("%c", s2[aux]);
			aux++;
		}
		printf("\n");
	}
	



	return 0;
}