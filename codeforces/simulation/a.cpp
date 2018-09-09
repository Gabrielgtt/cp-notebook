#include <bits/stdc++.h>
#define MAXN 200
using namespace std;

int main(){
	int arr[MAXN];
	int n, soma = 0;
	scanf("%d", &n);
	for (int i=0;i<n;i++){
		scanf("%d", &arr[i]);
		soma += arr[i];
	}
	sort(arr, arr+n);

	int a = 0, res = soma;

	for (int i=0; i<n; i++){
		a += arr[i];
		res = max(res, soma - (a * 2));
	}
	printf("%d\n", res);

	return 0;
}