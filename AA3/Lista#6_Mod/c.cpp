#include <bits/stdc++.h>
#define MAXN 10000010
#define ll long long
using namespace std;

bool notPrime[MAXN];
vector <ll> primes;
ll p, q, totiente;

void crivo(){
	for (ll i=2; i<90000; i++){
		if (!notPrime[i]){
			primes.emplace_back(i);
			for (ll j = i*i; j < MAXN; j += i){
				notPrime[j] = true;
			}
		}
	}
}

void PF(ll num){
	ll index = 0, pf = primes[index];
	while (pf * pf <= num){
		if (num % pf == 0) {
			p = pf;
			num/=pf;
			break; 
		}
		pf = primes[++index];  
	}
	if (num != 1) q = num;
}

ll negMod(ll num, ll mod){
	return num - ((num/mod - 1) * mod);
}

ll euclidesExtended(ll num1, ll num2){
	ll resto1 = num1, resto2 = num2;
	ll n1 = 1, m1 = 0, n2 = 0, m2 = 1;
	ll quo, restoAux, nAux, mAux;

	while (resto1 != 1){
		quo = resto1 / resto2;

		restoAux = resto1;
		nAux = n1;
		mAux = m1;

		resto1 = resto2;
		n1 = n2;
		m1 = m2;

		resto2 = restoAux - (quo * resto1); 
		n2 = nAux - (quo * n1);
		m2 = mAux - (quo * m1);
	}

	return n1 < 0 ? negMod(n1, totiente) : n1 % totiente;
}

ll fastExpo(ll num, ll e, ll mod){
	ll res = 1ll;
	while (e > 0){
		if (e & 1) res = ((res % mod) * (num % mod)) % mod;
		e = e >> 1;
		num = ((num % mod) * (num % mod)) % mod;
	}
	return res;
}

int main(){
	ll n, e, c;
	scanf("%lld %lld %lld", &n,&e,&c);
	crivo();
	PF(n);
	totiente = (p-1)*(q-1);
	ll d = euclidesExtended(e, totiente);
	printf("%lld\n", fastExpo(c, d, n));
	return 0;
}