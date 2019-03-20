#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000
using namespace std;

ll n, Cm, Co;
ll M[2][2];

void multiMatrix(ll Z[2][2], ll P[2][2]){
    ll x = ((((Z[0][0] % MOD) * (P[0][0] % MOD)) % MOD) + (((Z[0][1] % MOD) * (P[1][0] % MOD)) % MOD)) % MOD;
    ll y = ((((Z[0][0] % MOD) * (P[0][1] % MOD)) % MOD) + (((Z[0][1] % MOD) * (P[1][1] % MOD)) % MOD)) % MOD;
    ll z = ((((Z[1][0] % MOD) * (P[0][0] % MOD)) % MOD) + (((Z[1][1] % MOD) * (P[1][0] % MOD)) % MOD)) % MOD;
    ll w = ((((Z[1][0] % MOD) * (P[0][1] % MOD)) % MOD) + (((Z[1][1] % MOD) * (P[1][1] % MOD)) % MOD)) % MOD;

    M[0][0] = x;
    M[0][1] = y;
    M[1][0] = z;
    M[1][1] = w;
}

void expM(ll e){
	if (e == 0 || e == 1) return;

	expM(e/(ll)2);

	ll P[2][2]= {{Cm, Co}, {1, 0}};

	multiMatrix(M, M);
	if (e & (ll)1) multiMatrix(M, P);
}

ll solve(){
	n /= 5;
	Cm %= MOD;
	Co %= MOD;

	if (n == (ll) 1) return Cm;
	if (n == (ll) 2) return ((Cm * Cm) % MOD + Co) % MOD;
	else {
		M[0][0] = Cm;
		M[0][1] = Co;
		M[1][0] = 1;
		M[1][1] = 0;
		expM(n);
		return M[0][0];
	}
}

int main(){

	while (scanf("%lld %lld %lld", &n, &Cm, &Co) != EOF){
		ll res = solve();
		printf("%06lld\n", res);
	}

	return 0;
}
