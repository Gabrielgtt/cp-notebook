#include <bits/stdc++.h>

using namespace std;

int LCstr[60][60];

int LCstring(string frase1, string frase2, int len1, int len2){
	int result = 0;

	for (int i = 1; i <= len1; i++){
		for (int j = 1; j <= len2; j++){
			if (frase1[i-1] == frase2[j-1]){
				LCstr[i][j] = LCstr[i-1][j-1] + 1;
				result = max(result, LCstr[i][j]); 
			
			} else LCstr[i][j] = 0;

		}
	}

	return result;
}

int main(){
	string frase1, frase2;
	int len1, len2;
	memset(LCstr, 0, sizeof LCstr);

	while (getline(cin, frase1)){
		getline(cin, frase2);
		len1 = frase1.size();
		len2 = frase2.size();
		printf("%d\n", LCstring(frase1, frase2, len1, len2));
	}

	return 0;
}