#include <bits/stdc++.h>
#define MAXN 20000
#define ll long long
using namespace std;

ll gcd(ll a, ll b) {return b == 0 ? a : gcd(b, a%b);}
ll mmc(ll a, ll b) {return a * (b/gcd(a, b));}

ll primos[MAXN];

int main(){
	ll n;
	int k;
	scanf("%lld %d", &n, &k);

	ll res = n;
	for (int i=0; i<k; i++){
		scanf("%lld", &primos[i]);
		res -= n / primos[i];
	}

	for (int i=0; i<k; i++){
		for (int j=i+1; j<k; j++){
			res += n / (mmc(primos[i], primos[j]));
		}
	}

	for (int i=1; i<=30; i++){
		bool gamb = true;
		for (int j=0; j<k; j++){
			if (i % primos[j] == 0) gamb = false;
		}
		if (gamb) printf("%d ", i);
	}
	printf("\n");

	printf("%lld\n", res);
	return 0;
}