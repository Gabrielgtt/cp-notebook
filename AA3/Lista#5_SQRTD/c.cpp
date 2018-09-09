#include <bits/stdc++.h>
#define MAXN 100002
#define MAXR 230
using namespace std;

int gcd(int a, int b) {return b == 0 ? a : gcd(b , a%b);}
int mmc(int a, int b) {return a * (b / gcd(a, b));}

int arr[MAXN], freq[MAXN][MAXR], raiz, buckets[MAXN];
int n, m;
map <int, vector <int> > divs;
vector <int> primos;

void preDivs(int num){
	int sqr = sqrt(num);
	// printf("calc divs de %d\n", num);
	for (int i = 1; i <= sqr; i++){
		if (num % i == 0){
			divs[num].push_back(i);
			if (num/i <= 100000){
				divs[num].push_back(num/i);
			}
			// printf("%d %d ", i, num/i);
		}
	}
	// printf("\n");
}

int bloco(int id, int valor){
	int div = gcd(valor, buckets[id]);
	int aux = buckets[id];
	// printf("aux = %d, div = %d\n", aux, div);
	while (div != 1 && aux % div == 0) aux /= div;
	int soma = 0;
	// printf("Div %d no bloco %d de mult %d\n", aux, id, buckets[id]);
	if (divs[aux].size() == 0){
		preDivs(aux);
	}
	for (int i=0; i<divs[aux].size(); i++){
		soma += freq[divs[aux][i]][id];
	}
	return soma;
}

int main(){
	scanf("%d", &n);
	raiz = sqrt(n);
	for (int i=0; i < raiz+10; i++){
		buckets[i] = 1;
	}
	for (int i=0; i<n; i++){
		scanf("%d", &arr[i]);
		buckets[i/raiz] = mmc(buckets[i/raiz], arr[i]);
		freq[arr[i]][i/raiz]++;
	}

	// crivo();
	// printf("Raiz = %d\n", raiz);
	scanf("%d", &m);
	int tipo, left, right, valor, aux, div, res = 0;
	for (int i=0; i<m; i++){
		scanf("%d", &tipo);
		if (tipo == 1){
			scanf("%d %d", &left, &valor);
			left--;
			aux = left/raiz;
			freq[arr[left]][aux]--;
			freq[arr[valor]][aux]++;
			buckets[aux] /= arr[left];
			buckets[aux] *= valor;
			arr[left] = valor;

		} else if (tipo == 2){
			// scanf("%d %d %d", &left, &right, &valor);
			res = 0;
			left--; right--;
			// printf("%d %d\n", divs[valor].size() == 0, right - left >= raiz);
			if (divs[valor].size() == 0 && right - left >= raiz){
				preDivs(valor);
			}

			while (left < right && left % raiz != 0){
				res += gcd(arr[left], valor) == 1;
				left++;
			}

			while (left + raiz - 1 <= right){
				// printf("bloco em %d - %d\n", left, right);
				res += bloco(left/raiz, valor);
				left += raiz;
			}

			while (left <= right){
				res += gcd(arr[left], valor) == 1;
				left++;	
			}

			printf("%d\n", res);
		}
	}
	

	return 0;
}

// 90
// 10 9