#include <bits/stdc++.h>
using namespace std;

int main(){
	deque <int> fila;

	int q, num, tipo;

	scanf("%d", &q);
	while (q--){
		scanf("%d", &tipo);
		if (tipo == 1){
			scanf("%d", &num);
			fila.push_back(num);
		} else if (tipo == 2){
			if (!fila.empty()){
				fila.pop_front();
			}
		} else {
			if (!fila.empty()){
				printf("%d\n", fila.front());				
			} else {
				printf("Empty!\n");				
			}
			
		}
	}
	return 0;
}