#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------------------------ 
struct No {
	int v, l, r;
	No *le, *ri;

	No(int v_ = 0) : le(NULL), ri(NULL), v(v_) {}

	inline void init(int a, int b) { l = a, r = b; }
	
	void copy(No o) { // copie o necessario
		v = o.v;
	}

	No merge(No l, No r) { // faca seu merge
		No res = No();
		res.v = max(l.v, r.v);
		return res;
	}

	No query(int d, int p){
		if (p < l || r < d) return No(); //elemento neutro
		if (d <= l && r <= p) return No(v); // copia do atual
		No left = le ? le->query(d, p) : No();
		No right = ri ? ri->query(d, p) : No();
		return No().merge(left, right);
	}

	void update(int idx, int val){
		if (l == r) { copy(No(val)); return; }
		int m = l+((r-l)>>1);
		if (idx <= m) {
			if (!le) le = new No(), le->init(l, m);
			le->update(idx, val);
		} else {
			if (!ri) ri = new No(), ri->init(m+1, r);
			ri->update(idx, val);
		}
		copy(merge(le ? *le : No(), ri ? *ri : No()));
	}
};
// ------------------------------------------------------------------------------

int main() {
	No seg = No();
	int n = 10;
	seg.init(0, n-1);
	int arr[n] = {1, -1, 2, -4, 3, 5, 10, 3, -3, 5};
	for (int i=0; i<n; i++) seg.update(i, arr[i]);
	assert(seg.query(0, n-1).v == 10);
	seg.update(9, 100);
	assert(seg.query(0, n-1).v == 100);
	printf("Tudo certo!\n");
	return 0;
}
