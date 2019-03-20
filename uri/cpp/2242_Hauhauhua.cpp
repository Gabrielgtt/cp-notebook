#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin >> s;

	int tam = 0; 
	char pali[60];

	for (int i=0; i < s.size(); i++){
		if (s[i] == 'a' || s[i] == 'u' || s[i] == 'o' || s[i] == 'i' || s[i] == 'e'){
			pali[tam] = s[i];
			tam++;
		} 
	}

	for (int i=0; i < tam/2; i++){
		// printf("%d %d\n", i, i+tam-1);
		// printf("%d %d\n", pali[i], pali[i+tam-1]);
		if (pali[i] != pali[tam-i-1]){
			printf("N\n");
			return 0;
		}
	}

	printf("S\n");
	return 0;
}


