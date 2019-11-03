#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------------------------ 
struct Node {
	int v, l, r;
	Node *left, *right;

	Node(int val = 0) : left(NULL), right(NULL), v(val) {}

	inline void init(int a, int b){
		l = a, r = b;
	}
	
	void copy(Node o) {
		v = o.v;
	}

	Node merge(Node l, Node r) { // faca seu merge
		Node res = Node();
		res.v = max(l.v, r.v);
		return res;
	}

	Node query(int de, int para){
		if (para < l || r < de) return Node(); //elemento neutro
		if (de <= l && r <= para) return Node(v); // copia do atual
		Node le = left ? left->query(de, para) : Node();
		Node ri = right ? right->query(de, para) : Node();
		return Node().merge(le, ri);
	}

	void update(int idx, int val){
		if (l == r){
			copy(Node(val));
			return;
		}
		int m = l+(r-l)/2;
		if (idx <= m) {
			if (!left) left = new Node(), left->init(l, m);
			left->update(idx, val);
		} else {
			if (!right) right = new Node(), right->init(m+1, r);
			right->update(idx, val);
		}
		copy(merge(left ? *left : Node(), right ? *right : Node()));
	}
};
// ------------------------------------------------------------------------------ 26858543009 

int main() {
	Node seg = Node();
	int n = 10;
	seg.init(0, n-1);
	int arr[n] = {1, -1, 2, -4, 3, 5, 10, 3, -3, 5};
	for (int i=0; i<n; i++) seg.update(i, arr[i]);
	printf("%d\n", seg.query(0, n-1).v); // 10
	seg.update(9, 100);
	printf("%d\n", seg.query(0, n-1).v); // 100
	return 0;
}
