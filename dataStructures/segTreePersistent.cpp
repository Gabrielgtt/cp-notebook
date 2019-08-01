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
		left = l, right = r;
		Node res = merge(*l, *r);
		copy(res);
	}

} *seg[MAXN];

Node query(Node *v, int l, int r, int tl = 1, int tr = n){ // definir n global!!
	Node res = Node();
	if (tl > r || tr < l) return res;
	if (l <= tl && tr <= r) {
		res.copy(*v);
		return res;
	}
	int tm = tl + (tr-tl)/2;
	return res.merge(query(v->left, l, r, tl, tm), query(v->right, l, r, tm+1, tr));
}

Node *update(Node *v, int pos, int val, int tl = 1, int tr = n){
	if (tl == tr) return new Node(val);
	int tm = tl + (tr-tl)/2;
	if (pos <= tm)
		return new Node(update(v->left, pos, tl, tm), v->right);
	else  
		return new Node(v->left, update(v->right, pos, tm+1, tr));
}

Node *build(int tl = 1, int tr = n) {
	if (tl == tr) return new Node();
	int tm = tl + (tr-tl)/2;
	return new Node(build(tl, tm), build(tm+1, tr));
}
// ------------------------------------------------------------------------------ 30295129778
