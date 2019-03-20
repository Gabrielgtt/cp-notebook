#include <bits/stdc++.h>
using namespace std;

int flavious(int n, int k){
	if (n == 1) return 0;
	return (flavious(n-1, k) + k) % n;
}

int main(){
	int n;
	scanf("%d", &n);

	int a, b;
	for (int i=1; i<=n; i++){
		scanf("%d %d", &a, &b);
		printf("Case %d: %d\n", i, flavious(a, b) + 1);
	}

	return 0;
}