#include <bits/stdc++.h>
#define MAXN 100
using namespace std;

vector<int> linhas[MAXN];

int main(){
	int n;
	scanf("%d", &n);

	int aux;
	for(int i=0; i<n; i++){
		scanf("%d", &aux);
		linhas[0].push_back(aux);
	}

	int tam = n-1;
	for (int i=1; i<n; i++){
		for (int j=0; j<tam; j++){
			if (linhas[i-1][j] == linhas[i-1][j+1]) linhas[i].push_back(1);
			else linhas[i].push_back(-1);
		}
		tam--;
	}

	if (linhas[n-1][0] == -1){
		printf("branca\n");
	} else {
		printf("preta\n");
	}
}	