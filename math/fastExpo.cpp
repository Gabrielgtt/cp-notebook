#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll fastExpo(ll a, ll e) {
	ll res = 1;
	while (e > 0) {
		if (e & 1) res = res * a % MOD;
		a = a * a % MOD;
		e >>= 1;
	}
	return res;
}
