#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

typedef long long ll;
typedef pair <ll, ll> ii;

const int INF = 1e9;
const int MAXN = 200010;

ll n, b;

ii solve(ll x, ll y, ll comeco, ll lado){
	b -= comeco;

	if (b <= lado){
		x += b;
		return ii(x, y);
	} else {
		x += lado;
		b -= lado;
	}

	lado--;

	if (b <= lado){
		y += b;
		return ii(x, y);
	} else {
		y += lado;
		b -= lado;
	}

	if (b <= lado){
		x -= b;
		return ii(x, y);
	} else {
		x -= lado;
		b -= lado;
	}

	if (b <= lado){
		y -= b;
		return ii(x, y);
	}

	return ii(-1e17, -1e17);
}

int main(){

	scanf("%lld %lld", &n, &b);

	ll left = 1, right = (n+1)/2;


	while(left <= right){
		ll mid = (left+right)/2;

		ll ladoMenor = (2ll*mid) - ((int)(n&1));

		ll pulo = (n*n) - (ladoMenor*ladoMenor);

		if (pulo > b){
			left = mid+1;

		} else {
			ll caminho = pulo + (4ll * (ladoMenor - 1)) + (ladoMenor&1);

			if (b <= caminho){
				ll x, y;
				x = y = ((n-ladoMenor)/2)+1;  
				ii res = solve(x-1, y, pulo, ladoMenor);
				printf("%lld %lld\n", res.second, res.first);
				break;

			} else {
				right = mid-1;
			}
		}
	}
	return 0;
}