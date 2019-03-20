#include <bits/stdc++.h>
using namespace std;

int main(){
	map <string, double> precos;
	int n, m, t;
	scanf("%d", &t);
	string palavra;
	double preco;
	while (t--){
		scanf("%d", &n);
		while (n--){
			cin >> palavra >> preco;
			precos[palavra] = preco;
		}
		scanf("%d", &m);
		double res = 0.0;
		int qtd;
		while (m--){
			cin >> palavra >> qtd;
			res += precos[palavra] * qtd;
		}
		printf("R$ %.2f\n", res);
	}

	return 0;
}