#include <bits/stdc++.h>
#define MAXN 20000
using namespace std;

int arr[MAXN], acm[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%d", &arr[i]);
		if (i > 0) acm[i] = abs(arr[i] - arr[i-1]);
	}

	int aux = 0;
	int res = 0;
	for (int i=1; i<n; i++){
		aux++;
		if (acm[i] > 1) res = max(res, aux), aux = 0;
	}

	printf("%d\n", max(res, aux+1));
	return 0;
}