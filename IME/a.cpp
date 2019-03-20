#include <bits/stdc++.h>
#define MAXN 10001000
#define MOD 1000000007
#define ll long long
using namespace std;

ll res[MAXN];
ll acm[MAXN];
int main(){
	int n;

	res[0] = 1;
	res[2] = 3;
	acm[0] = 2;

	scanf("%d", &n);

	if (n & 1) {
		printf("0\n");
		return 0;
	}

	for (int i=4; i<=n; i+=2){
		res[i] = (((3 * res[i-2]) % MOD) + acm[i-4]) % MOD;
		acm[i-2] = (((2 * res[i-2]) % MOD) + acm[i-4]) % MOD;
	}

	printf("%lld\n", res[n]);

	return 0;
}