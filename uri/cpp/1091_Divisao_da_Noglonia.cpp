#include <bits/stdc++.h>

using namespace std;

int main(){
	int k, c1, c2;
	
	while (scanf("%d", &k) && k != 0){
		scanf("%d %d", &c1, &c2);

		int a, b;

		for (int i=0; i<k; i++){
			scanf("%d %d", &a, &b);

			if (a == c1 || b == c2){
				printf("divisa\n");
			} else if (a > c1){
				if (b > c2){
					printf("NE\n");
				} else {
					printf("SE\n");
				}
			} else if (a < c1){
				if (b < c2){
					printf("SO\n");
				} else {
					printf("NO\n");
				}
			}
		}
	}


	return 0;
}