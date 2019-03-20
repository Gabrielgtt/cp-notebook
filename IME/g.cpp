#include <bits/stdc++.h>
#define MAXN 200010
#define MOD 1000000007
#define ll long long
using namespace std;

bool stock[MAXN];
int num[MAXN];

set <int> divs;



int main(){
	int n, t;
	scanf("%d %d", &n, &t);

	for (int i=0;i<n;i++){
		scanf("%d", &num[i]);
	}

	ll total = 0;
	int qtdNums = 0;
	int aux;
	for (int i=0; i<t; i++){
		scanf("%d", &aux);

		stock[aux] ^= 1;
		if (stock[aux]){ //adicionado
			qtdNums++;
			total = qtdNums * (qtdNums-1) / 2;

			//tirar todos os conectados;
			conectar(aux);
		}

	}

	return 0;
}