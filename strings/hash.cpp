#include <bits/stdc++.h>
using namespace std;

// ----------------------------------------------------------------------
typedef long long ll;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
 
int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}
 
template<int MOD> struct Hash {
	static int P;
	int n;
	string s;
	vector<ll> h, power;
	Hash() {}
	Hash(string s_): n(s_.size()), s(s_), h(n), power(n) {
		power[0] = 1;
		for (int i = 1; i < n; i++) power[i] = power[i-1]*P % MOD;
		h[0] = s[0];
		for (int i = 1; i < n; i++) h[i] = (h[i-1]*P + s[i]) % MOD;
	}
	ll operator()(int i, int j){ // returna hash da substring s[i..j]
		if (!i) return h[j];
		return (h[j] - h[i-1]*power[j-i+1] % MOD + MOD) % MOD;
	}
};

template<int MOD> int Hash<MOD>::P = uniform(27, MOD-1);

template<int MOD> struct Pali {
	Hash <MOD> pre, suf;
	Pali(string s) {
		pre = Hash<MOD>(s);
		reverse(s.begin(), s.end());
		suf = Hash<MOD>(s);
	}
	bool operator()(int l, int r) {
		return pre(l, r) == suf(pre.n-1-r, pre.n-1-l);
	}
};
// ----------------------------------------------------------------------

int main() {
	string word = "testesabacabateste";
	Hash<(int)1e9+7> hs(word);
	Pali<(int)1e9+7> pa(word);
	assert(hs(0, 4) == hs(13, 17));
	assert(pa(6, 12));
}
