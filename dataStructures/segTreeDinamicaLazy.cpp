#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------------------------ 
struct Node {
	int v, l, r, lazy;
	Node *left, *right;

	Node(int val = 0) : left(NULL), right(NULL), v(val), lazy(0) {}

	inline void init(int a, int b){
		l = a, r = b;
	}
	
	void copy(Node o) {
		v = o.v;
	}

	Node merge(Node l, Node r) { // faca seu merge
		Node res = Node();
		res.v = l.v + r.v;
		return res;
	}

	void doLazy() {
		v += lazy * (r-l+1);
		if (l != r) {
			left->lazy += lazy;
			right->lazy += lazy;
		}
		lazy = 0;
	}

	inline void extend() {
		if (!left && l != r) {
			int m = l+(r-l)/2;
			left = new Node();
			left->init(l, m);
			right = new Node();
			right->init(m+1, r);
		}
		doLazy();
	}

	Node query(int de, int para){
		extend();
		if (para < l || r < de) return Node(); //elemento neutro
		if (de <= l && r <= para) return Node(v); // copia do atual
		return Node().merge(left->query(de, para), right->query(de, para));
	}

	void update(int de, int para, int val){
		extend();
		if (para < l || r < de) return;
		if (de <= l && r <= para) {
			lazy += val;
			doLazy();
			return;
		}
		left->update(de, para, val);
		right->update(de, para, val);
		copy(merge(*left, *right));
	}

} *root;
// ------------------------------------------------------------------------------ 30931463913

int main() {
	int n = 10;
	int arr[n] = {1, 3, 5, -3, 5, -3, 5, -3, 23, 53};
	root = new Node();
	root->init(0, 9);
	for (int i=0; i<n; i++) {
		root->update(i, i, arr[i]);
	}
	printf("%d\n", root->query(1, 3).v);
	root->update(3, 5, 10);
	root->update(0, 1, -3);
	printf("%d\n", root->query(1, 3).v);
	return 0;
}
