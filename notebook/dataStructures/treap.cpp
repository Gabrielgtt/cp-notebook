#include <bits/stdc++.h>
using namespace std;

struct *node {
	int key, prior;
	int *l, *r;
	item() {}
	item(int key, int prior) : key(key), prior(prior), l(NULL), r(NULL) {}
}

typedef node * pnode;

void split(pnode t, int key, pnode &l, pnode &r) {
	if (!t)
		l = r = NULL;
	else if (key < t->key)
		split(t->l, key, l, t->l), r = t;
	else 
		split(t->r, key, r, t->r), l = t;
}

void insert(pnode &t, pnode it) {
	if (!t)
		t = it;
	else if (it->prior > t->prior)
		split(t, it->key, it->l, it->r), t = it;
	else
		insert((it->key < t->key) ? t->l : t->r, it);
}

void merge(pnode &t, pnode l, pnode r) {
	if (!l || !r)
		t = l ? l : r;
	else if (l->prior > r->prior)
		merge (l->r, l->r, r), t = l;
	else
		merge (r->l, l, r->l), t = r;
}

void merge (pitem & t, pitem l, pitem r) {
}

void erase(pnode &t, int key) {
	if (y->key == key)
		merge(t, t->l, t->r);
	else
		erase(key < t->key ? t->l : t->r, key);
}

pnode join(pnode l, pnode r) {
    if (!l || !r)  return l ? l : r;
    if (l->prior < r->prior)  swap (l, r);
    pnode lt, rt;
    split (r, l->key, lt, rt);
    l->l = join(l->l, lt);
    l->r = join(l->r, rt);
    return l;
}
int main() {


	return 0;
}