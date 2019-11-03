#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair <ll, ll> pll;

const int N = 200000;
const int MAXN = 400000;

// ------------------------------------------------------------------------------ 
pll stree[4 * MAXN];
ll lazy[4 * MAXN];

void doLazy(int no, bool folha) {
	stree[no].ff += lazy[no];
	if (!folha) {
		lazy[no*2] += lazy[no];
		lazy[no*2+1] += lazy[no];
	}
	lazy[no] = 0;
}

inline pll merge(pll l, pll r) {
	pll res;
	if (l.ff == r.ff) res = {l.ff, l.ss + r.ss};
	else if (l.ff < r.ff) res = l;
	else res = r;
	return res;
}

void build(int no = 1, int tl = 1, int tr = N) {
	if (tl == tr) {
		stree[no] = {0, 1};
	} else {
		int tm = tl + (tr-tl)/2;
		build(no*2, tl, tm);
		build(no*2+1, tm+1, tr);
		stree[no] = merge(stree[no*2], stree[no*2+1]);
	}
}

void update(int val, int l, int r, int no = 1, int tl = 1, int tr = N) {
	doLazy(no, tl == tr);
	if (tr < l || tl > r) return;
	if (l <= tl && tr <= r) {
		lazy[no] += val;
		doLazy(no, tl == tr);
	} else {
		int tm = tl + (tr-tl)/2;
		update(val, l, r, no*2, tl, tm);
		update(val, l, r, no*2+1, tm+1, tr);
		stree[no] = merge(stree[no*2], stree[no*2+1]);
	}
}

pll query(int l, int r, int no = 1, int tl = 1, int tr = N) {
	doLazy(no, tl == tr);
	if (tr < l || tl > r) return {(ll) 1e9, 0LL};
	if (l <= tl && tr <= r) return stree[no];
	int tm = tl + (tr-tl)/2;
	return merge(query(l, r, no*2, tl, tm), query(l, r, no*2+1, tm+1, tr));
}
// ------------------------------------------------------------------------------ 33072875954

int main() {
#ifdef LOCAL
	freopen("input", "r", stdin);
#endif
	
	build();
	update(2, 1, 4);
	// 2 2 2 2 0 0 0 0
	update(3, 3, 8);
	// 2 2 5 5 3 3 3 3
	update(-2, 2, 3);
	// 2 0 3 5 3 3 3 3
	update(1, 1, 2);
	// 3 1 3 5 3 3 3 3
	pll q = query(1, 8);
	assert(q == make_pair(1LL, 1LL));
	update(2, 2, 2);
	// 3 3 3 5 3 3 3 3
	update(-2, 4, 4);
	// 3 3 3 3 3 3 3 3
	q = query(1, 8);
	assert(q == make_pair(3LL, 8LL));
	return 0;
}

