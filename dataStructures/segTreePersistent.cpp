#include <bits/stdc++.h>
#define MAXN 5000000
using namespace std;

struct Node {
	ll val;
	Node *left, *right;

	Node(const int value = 0) : left(NULL), right(NULL), val(value) {}
	Node(Node *l, Node *r) : left(l), right(r), val(0) {
		if (left) val += left->val;
		if (right) val += right->val;
	}

} *segTree[MAXN];

Node* build(int a[], int tl, int tr){
	if (tl == tr){
		return new Node(a[tl]);
	}
	int tm = tl + (tr-tl)/2;
	return new Node(build(a, tl, tm), build(a, tm+1, tr));
}

int query(Node* v, int tl, int tr, int l, int r){
	if (r < tl || l > tr) return 0;
	if (l <= tl && tr <= r) return v->val;
	int tm = tl + (tr-tl)/2;
	return query(v->left, tl, tm, l, r) 
		 + query(v->right, tm+1, tr, l, r);
}

Node* update(Node* v, int tl, int tr, int pos, int value){
	if (tl == tr) return new Node(value);
	int tm = tl + (tr-tl)/2;
	if (pos <= tm)
		return new Node(update(v->left, tl, tm, pos, value), v->right);
	else 
		return new Node(v->left, update(v->right, tm+1, tr, pos, value));
}

int main(){
	return 0;
}
