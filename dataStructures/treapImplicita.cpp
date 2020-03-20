#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------------------------
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

struct node {
	int soma;
    int v, prior, cnt;
    node * l, * r;
    node() : cnt(0) { }
    node (int v, int prior) : v(v), prior(prior), l(NULL), r(NULL) { }
};
typedef node * pnode;

int soma(pnode t) { return t ? t->soma : 0; }

void upd_soma(pnode t) {
	if (t) t->soma = t->v + soma(t->l) + soma(t->r);
}

int cnt(pnode t) { return t ? t->cnt : 0; }

void upd_cnt (pnode t) {
    if (t) t->cnt = 1 + cnt(t->l) + cnt (t->r);
}

void split (pnode t, pnode & l, pnode & r, int key, int add = 0) {
    if (!t) return void( l = r = 0 );
    int cur_key = add + cnt(t->l); //implicit key
    if (key <= cur_key)
        split (t->l, l, t->l, key, add),  r = t;
    else
        split (t->r, t->r, r, key, add + 1 + cnt(t->l)),  l = t;
    upd_cnt (t);
    upd_soma (t);
}


void merge (pnode & t, pnode l, pnode r) {
    if (!l || !r) t = l ? l : r;
    else if (l->prior > r->prior) merge (l->r, l->r, r), t = l;
    else merge (r->l, l, r->l), t = r;
    upd_cnt(t);
	upd_soma(t);
}

void insert(pnode & t, int pos, int val) {
	pnode t1 = NULL, t2 = NULL;
	split(t, t1, t2, pos);
	merge(t1, t1, new node(val, rng()));
	merge(t, t1, t2);
}
// ------------------------------------------------------------------------------ 35343927739

ostream& operator<< (ostream& os, pnode no) {
	if (!no) return os << "";
	return os << no->v << " " << no->l << no->r;
}

int main() {
	pnode raiz = NULL;

	insert(raiz, 1, 4);
	insert(raiz, 2, 3);
	insert(raiz, 3, 2);
	insert(raiz, 4, 3);

	pnode t1 = NULL, t2 = NULL;

	split(raiz, t1, t2, 2);
	assert(soma(t1) == 7);
	assert(soma(t2) == 5);

	pnode t11 = NULL, t12 = NULL;
	split(t1, t11, t12, 1);
	assert(soma(t11) == 4);

	merge(raiz, t11, t2);
	assert(soma(raiz) == 9);
	printf("Tudo certo!\n");
	return 0;
}
