#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int arr[MAXN], acm[MAXN];

int main(){
	int c, n, tam;
	scanf("%d %d", &c, &n);
	tam = c/n;
	for (int i=0; i<n; i++){
		scanf("%d", arr + i);
		if (arr[i] == 0) acm[c] = 1;
		else acm[arr[i]] = 1;
	}

	for (int i=1; i<=c; i++){
		acm[i] += acm[i-1]; 
	}

	bool flag = true;
	for (int i = 0; i < tam; i++){
		int j;
		flag = true;
		for (j = i; j <= c - tam; j += tam){
			if (acm[j+tam] - acm[j] != 1){
				flag = false;
				break;
			}
		}
		if (i > 0 && flag){
			if (n - acm[j] + acm[j+tam-c] != 1){
				flag = false;
			}
		}

		if (flag){
			printf("S\n");
			return 0;
		}
	}

	printf("N\n");
	return 0;
}

