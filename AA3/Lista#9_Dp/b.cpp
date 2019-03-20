#include <bits/stdc++.h>
#define ll long long
#define MAXN 1010
using namespace std;

int res[MAXN]; 

int main(){
	int t;
	scanf("%d", &t);
	ll x, n;

	while (t--){
		scanf("%lld %lld", &x, &n);

		for (ll i=1; i<=n; i++){
			ll ans = x/n;
			if (n - (x%n-1) <= i) ans++;
			printf("%lld\n", ans);
		}
	}

	return 0;
}
