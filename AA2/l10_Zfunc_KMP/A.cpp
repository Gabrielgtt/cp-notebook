#include <bits/stdc++.h>
#define MAXN 2000010
using namespace std;

int z[MAXN], tam;
string linha;
void zFunc(){
	memset(z, 0, sizeof z);
	int right = 0, left = 0, k1;

	for (int k=1; k<tam; k++){
		if (k > right){
			left = right = k;
			while (right < tam && linha[right] == linha[right-left]) right++;
			z[k] = right - left;
			right--;			
		} else {
			k1 = k - left;
			if (z[k1] < right - k + 1){ // dentro da janela
				z[k] = z[k1];
			} else {
				left = k;
				while (right < tam && linha[right] == linha[right-left]) right++;
				z[k] = right - left;
				right--;				
			}
		}
	}
}


int main(){

	while (cin >> linha){
		if (linha == ".") break;
		tam = linha.size();
		zFunc();
		bool flag = true;
		for (int i=1; i<tam; i++){
			if ((z[i] + i == tam) && (tam % i == 0)){
				printf("%d\n", tam/i);
				flag = false;
				break;
			}
		}
		if (flag) printf("1\n");
	}
	return 0;
}