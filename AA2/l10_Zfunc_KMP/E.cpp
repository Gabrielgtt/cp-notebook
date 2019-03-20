#include <bits/stdc++.h>
#define MAXN 2000010
using namespace std;

int z[MAXN], back[MAXN], tam;
string word;

void solve(){
	int right = 0, left = 0, kzin, a = 0, b = -1;

	back[0] = -1;
	while (a < tam){
		while (b >= 0 && word[a] != word[b]) b = back[b];
		a++, b++;
		back[a] = b;
		printf("%d ", back[a]);
	}
	printf("\n");

	if (back[tam] == 0){
		printf("Just a legend\n");
		return;
	}

	for (int k=1; k<tam; k++){
		if (k > right){
			left = right = k;
			while (right < tam && word[right] == word[right-left]) right++;
			z[k] = right - left;
			right--;			
		} else {
			kzin = k - left;
			if (z[kzin] < right - k + 1){
				z[k] = z[kzin];
			} else {
				left = k;
				while (right < tam && word[right] == word[right-left]) right++;
				z[k] = right - left;
				right--;				
			}
		}
	}

	int aux = 0;
	while (z[aux] != back[tam]) aux++;

	if (aux + back[tam] >= tam){
		aux++;
		while (!z[aux]){
			aux++;
			if (aux > tam){
				printf("Just a legend\n");
				return;
			}	
		} 
	}

	for (int i=aux; i<aux+back[tam] && i < tam; i++){
		printf("%c", word[i]);
	}
	printf("\n");
}


int main(){
	cin >> word;
	tam = word.size();
	solve();

	return 0;
}