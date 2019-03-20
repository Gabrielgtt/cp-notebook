#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

typedef long long ll;
typedef pair <int, int>  ii;
typedef  pair <int, ii>  iii;

const int MAXN = 2010;

ll gcd(ll a, ll b){
	return b == 0ll ? a : gcd(b, a%b);
}

int main(){
	ll N, M, k, n, m;

	scanf("%lld %lld %lld", &N, &M, &k);
		
	n = N / gcd(N, k);
	k = k / gcd(N, k);

	m = M / gcd(M, k);
	k = k / gcd(M, k);

	if (k > 2){
		printf("NO\n");
	} else if (k == 2){
		printf("YES\n");
		printf("%lld %lld\n", 0ll, 0ll);
		printf("%lld %lld\n", n, 0ll);
		printf("%lld %lld\n", 0ll, m);

	} else {

		if (2*n <= N){
			printf("YES\n");
			printf("%lld %lld\n", 0ll, 0ll);
			printf("%lld %lld\n", n*2ll, 0ll);
			printf("%lld %lld\n", 0ll, m);			
		} else if (2*m <= M){
			printf("YES\n");
			printf("%lld %lld\n", 0ll, 0ll);
			printf("%lld %lld\n", n, 0ll);
			printf("%lld %lld\n", 0ll, m*2ll);			
		} else {
			printf("NO\n");
		}
	}

	return 0;
}
