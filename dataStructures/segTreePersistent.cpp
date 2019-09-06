#include <bits/stdc++.h>
#define MAXN 2010000
using namespace std;

int N;

// ------------------------------------------------------------------------------ 
struct Node {
	int v;
	Node *left, *right;

	Node(int val = 0) : v(val) {}

	Node merge(Node l, Node r) { // codar seu merge!!
		Node res = Node();
		res.v = l.v + r.v;
		return res;
	}

	void copy(Node de) { // setar para todos os param!!
		v = de.v;
	}

	Node(Node *l, Node *r) {
		// if (!l) l = new Node(); // para implicitas!
		// if (!r) r = new Node(); // para implicitas!
		left = l, right = r;
		copy(merge(*l, *r));
	}

} *seg[MAXN];

Node query(Node *v, int l, int r, int tl = 1, int tr = N){ // definir n global!!
	// if (!v) v = new Node(); // para implicitas!
	Node res = Node();
	if (tl > r || tr < l) return res;
	if (l <= tl && tr <= r) {
		res.copy(*v);
		return res;
	}
	int tm = tl + (tr-tl)/2;
	return res.merge(query(v->left, l, r, tl, tm), query(v->right, l, r, tm+1, tr));
}

Node *update(Node *v, int pos, int val, int tl = 1, int tr = N){
	// if (!v) v = new Node(); // para implicitas!
	if (tl == tr) return new Node(val);
	int tm = tl + (tr-tl)/2;
	if (pos <= tm)
		return new Node(update(v->left, pos, val, tl, tm), v->right);
	else  
		return new Node(v->left, update(v->right, pos, val, tm+1, tr));
}

Node *build(int tl = 1, int tr = n) {
	if (tl == tr) return new Node();
	int tm = tl + (tr-tl)/2;
	return new Node(build(tl, tm), build(tm+1, tr));
}
// ------------------------------------------------------------------------------
// hash n tem os comentários !!

int main() {
	return 0;
}
