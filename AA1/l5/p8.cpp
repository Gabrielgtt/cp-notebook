#include <bits/stdc++.h>

using namespace std;

int main(){
	string frase;

	while (cin >> frase){
		stack <int> pilha;

		int x = 0;
		for (int i=0; i < frase.size(); i++){
			if (frase[i] == ')' || frase[i] == '('){
				pilha.push(frase[i]);
				x++;
			}
		}

		int aux=0, flag = 0;
		for (int i=0; i < x; i++){

			if (pilha.top() == ')'){
				aux++;
			} else {
				aux--;
			}

			pilha.pop();

			if (aux < 0){
				flag = 1;
				break;
			}
		}

		if (aux != 0 || flag){
			printf("incorrect\n");
		} else {
			printf("correct\n");
		}

	}


	return 0;
}
