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

	inline void extend() {
		if (!left && l != r) {
			int m = l+(r-l)/2;
			left = new Node();
			left->init(l, m);
			right = new Node();
			right->init(m+1, r);
		}
	}

	Node query(int de, int para){
		if (para < l || r < de) return Node(); //elemento neutro
		if (de <= l && r <= para) return Node(v); // copia do atual
		extend();
		return Node().merge(left->query(de, para), right->query(de, para));
	}

	void update(int idx, int val){
		if (l == r){
			copy(Node(val));
			return;
		}
		extend();
		(idx <= left->r ? left : right)->update(idx, val);
		copy(merge(*left, *right));
	}
};
// ------------------------------------------------------------------------------ 26141053943

int main() {
	return 0;
}
