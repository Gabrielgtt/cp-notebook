#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, v;

	while (1){
		scanf("%d", &n); // NUM DE VAGOES
		if (n==0) break;

		while (1){
			stack<int> chegando;
			stack<int> estacao;
			int flag=0;

			for (int i=0; i<n; i++){
				scanf("%d", &v);
				if (v==0){
					flag = 1;
					break;
				} else {
					chegando.push(v);
				}	
			} // Agora todos os vagoes estao em chegando na ordem inversa

			if (flag) break;
			int dentro=0, last=1000000;
			
			for (int j=0; j<n; j++){

				// printf("%d\n", chegando.top());

				if (!estacao.empty()){
					
					while (!(estacao.empty()) && estacao.top() > chegando.top()) {

						if (estacao.top() > last) {  
							flag = 1;
							break;
						}

						last = estacao.top();						
						estacao.pop(), dentro--;
					}
					
				}

				estacao.push(chegando.top()), dentro++;


				if (flag) break;

				chegando.pop();
			}

			// printf("last = %d, dentro = %d\n", last, dentro);

			if (flag == 0){
				for (int trem=0; trem < dentro; trem++){
					// printf("%d\n", estacao.top());
					if (estacao.top() < last || last == 1000000) { 
						last = estacao.top();
						estacao.pop();

					 } else break;
				}
			}


			if (estacao.empty()) printf("Yes\n");
			else printf("No\n");

		}

		printf("\n");
	}
	return 0;
}