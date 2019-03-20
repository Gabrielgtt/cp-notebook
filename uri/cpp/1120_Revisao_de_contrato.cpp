#include <bits/stdc++.h>

using namespace std;

int main(){
	char n, atual;
	int flag, flag2;
	string original;

	while (1){
		cin >> n >> original;

		if (n == '0') break;

		flag = flag2 = 0;

		for (string::iterator it = original.begin(); it != original.end(); it++){
			atual = *it; 
			if (atual != n){

				if (atual == '0'){
					if (flag){
						printf("0");
						flag2 = 1;
					}

				} else {
					flag = flag2 = 1;
					printf("%c", atual);
				}
			}
		}

		if (flag2 == 0){
			printf("0\n");
		} else {
			printf("\n");
		}
	}

	cin >> original;
	return 0;
}