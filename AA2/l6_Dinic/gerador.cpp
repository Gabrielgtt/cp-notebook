#include <bits/stdc++.h>
using namespace std;

int main(){

	printf("5000 30000\n");
	
	srand(time(NULL));
	for (int i=1; i<=30000; i++){
		int de = rand() % 5000 + 1;
		int para = rand() % 5000 + 1;
		int custo = rand() % 1000000000 + 1;
		printf("%d %d %d\n", de, para, custo);
	}

	return 0;
}