#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------------------------ 
struct No {
	int v, l, r, lazy;
	No *le, *ri;

	No(int val = 0) : le(NULL), ri(NULL), v(val), lazy(0) {}

	inline void init(int a, int b){
		l = a, r = b;
	}
	
	void copy(No o) {
		v = o.v;
	}

	No merge(No l, No r) { // faça seu merge
		No res = No();
		res.v = l.v + r.v;
		return res;
	}

	void doLazy() { // faça sua lazy
		v += lazy * (r-l+1);
		if (l != r) {
			le->lazy += lazy;
			ri->lazy += lazy;
		}
		lazy = 0;
	}

	inline void extend() {
		if (!le && l != r) {
			int m = l+(r-l)/2;
			le = new No();
			le->init(l, m);
			ri = new No();
			ri->init(m+1, r);
		}
		doLazy();
	}

	No query(int de, int para){
		extend();
		if (para < l || r < de) return No(); //elemento neutro
		if (de <= l && r <= para) return No(v); // copia do atual
		return merge(le->query(de, para), ri->query(de, para));
	}

	void update(int de, int para, int val){
		extend();
		if (para < l || r < de) return;
		if (de <= l && r <= para) {
			lazy += val;
			doLazy();
			return;
		}
		le->update(de, para, val);
		ri->update(de, para, val);
		copy(merge(*le, *ri));
	}

} *root;
// ------------------------------------------------------------------------------ 30931463913

int main() {
	int n = 10;
	int arr[n] = {1, 3, 5, -3, 5, -3, 5, -3, 23, 53};
	root = new No();
	root->init(0, n-1);
	for (int i=0; i<n; i++) {
		root->update(i, i, arr[i]);
	}
	assert(root->query(0, 3).v == 6);
	root->update(3, 5, 10);
	assert(root->query(1, 3).v == 15);
	root->update(0, 1, -3);
	assert(root->query(1, 3).v == 12);
	assert(root->query(9, 9).v == 53);
	printf("Tudo certo!\n");
	return 0;
}
