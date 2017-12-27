#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, flag, izao;
	int letra[6];

	while (scanf("%d", &n) && n != 0){
		
		while (n--) {
			flag = izao = 0;
			scanf("%d %d %d %d %d", &letra[0], &letra[1], &letra[2] , &letra[3], &letra[4]);

			for (int i=0; i<5; i++){
				if (letra[i] <= 127){
					if (flag){
						printf("*\n");
						flag = 2;
						break;
					} else flag = 1, izao = i;
				}
			}

			if (flag == 1){
				printf("%c\n", izao+65);
			} else if (flag == 0) printf("*\n");

		}
	}
}