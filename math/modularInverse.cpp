ll gcdExtended(ll a, ll b, ll& x, ll& y) {
    x = 1, y = 0;
    ll x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        ll q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

ll modularInverse(ll a, ll mod = MOD) {
	ll x, y;
	ll g = gcdExtended(a, mod, x, y);
	assert(g == 1);
	return (x % mod + mod) % mod;
}
