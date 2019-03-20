#include <bits/stdc++.h>
#define ll long long
#define INF 2e9
#define MAXSQRT 780
#define MAXN 700000
using namespace std;

int n, q;
int iFila = 0;

struct nodeSQRT{
	int raiz;
	int maior;
	int size;
	list <int> arr;
	nodeSQRT *prox;

	nodeSQRT(int sqr){
		this->raiz = sqr;
		this->maior = -1;
	}

	void add(int num, int pos){
		if (pos >= this->raiz){
			if (prox == NULL) prox = new nodeSQRT(this->raiz);

			prox->add(num - (this->raiz));

		} else {
			maior = max(maior, num);

			if ()
		}
	}


	
} *fila;



int main(){
	scanf("%d", &n);

	fila = new nodeSQRT(sqrt(n));

	int aux;
	for (int i=0; i<n; i++){
		scanf("%d", &aux);
		fila->add(aux, i);
	}	

	scanf("%d", &q);

	int tipo, index, soma;
	for (int i=0; i<q; i++){
		scanf("%d", &tipo);

		if (tipo == 0){
			// scanf("%d")
		}
	}

	return 0;
}