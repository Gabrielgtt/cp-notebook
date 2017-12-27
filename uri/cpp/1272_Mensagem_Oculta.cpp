#include <bits/stdc++.h>

using namespace std;

int main(){
	string frase;
	int n, flag;
	scanf("%d", &n);
	cin.ignore();

	while (n--){
		getline(cin, frase);
		flag = 1;

		for (int i=0; i<frase.size(); i++){
			if (flag && frase[i] != ' '){
				printf("%c", frase[i]);
				flag = 0;
			} else if (!flag && frase[i] == ' ') flag = 1;
		}
		printf("\n");

	}
	return 0;
}