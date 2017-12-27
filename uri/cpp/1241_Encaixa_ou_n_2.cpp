#include <bits/stdc++.h>

using namespace std;

int main(){	
	string s1, s2;
	int n, tam1, tam2, flag;
	scanf("%d", &n);

	while (n--){
		cin >> s1 >> s2;
		flag = 1;
		tam1 = s1.size();
		tam2 = s2.size();

		if (tam1 >= tam2){
			for (int i=tam1-tam2; i<tam1; i++){
				if (s1[i] != s2[i-tam1+tam2]){
					flag = 0;
					break;
				}
			}

		} else flag = 0;

		if (flag) printf("encaixa\n");
		else printf("nao encaixa\n");
	}


	return 0;
}