#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;

	long long int somat = 0;
	int a, b;

	scanf("%d", &n);
	for (int i = 0; i<n; i++){
		scanf("%d %d", &a, &b);
		somat += a*b;
	}

	printf("%lld\n", somat);

	return 0;
}