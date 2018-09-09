#include <bits/stdc++.h>
using namespace std;
	
int main(){
	long long l, n;
	scanf("%lld %lld", &l, &n);

	n -= 1ll;
	long long res = (l-n)*(l-n) + n;

	printf("%lld\n", res);

	return 0;
} 