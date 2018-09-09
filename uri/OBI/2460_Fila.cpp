#include <bits/stdc++.h>
#define MAXN 300000
using namespace std;

int n, arr[MAXN], flag[MAXN], m;
int main(){
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	scanf("%d", &m);
	int aux;
	for (int i=0; i<m; i++){
		scanf("%d", &aux);
		flag[aux] = 1;
	}
	bool printed = false;
	for (int i=0; i<n; i++){
		if (!flag[arr[i]]){
			if (printed) printf(" ");
			printed = true;
			printf("%d", arr[i]);
		}
	}
	printf("\n");

	return 0;
}