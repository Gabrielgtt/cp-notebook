#include <bits/stdc++.h>
using namespace std;

deque <int> fila;

void func(int n){

	while (n) fila.push_back(n--);

	printf("Discarded cards: ");

	bool flag = false;
	while (fila.size() != 1){
		
		if (flag) printf(", %d", fila.back());
		else printf("%d", fila.back()), flag = true;

		fila.pop_back();
		fila.push_front(fila.back());
		fila.pop_back();
	}
	printf("\n");
	printf("Remaining card: %d\n", fila.back());
	fila.pop_back();
}

int main(){
	int n;

	while (scanf("%d", &n) && n!=0){
		func(n);
	}

	return 0;
}