#include <bits/stdc++.h>
#define MAXN 300000
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

void print(pnode no) {
	if (!no) return;
	printf("%d\n", no->v);
	print(no->l), print(no->r);
}

int soma(pnode t) {
	return t ? t->soma : 0;
}

void upd_soma(pnode t) {
	if (t)
		t->soma = t->v + soma(t->l) + soma(t->r);
}

int cnt (pnode t) {
    return t ? t->cnt : 0;
}

void upd_cnt (pnode t) {
    if (t)
        t->cnt = 1 + cnt(t->l) + cnt (t->r);
}

void split (pnode t, pnode & l, pnode & r, int key, int add = 0) {
    if (!t)
        return void( l = r = 0 );
    int cur_key = add + cnt(t->l); //implicit key
    if (key <= cur_key)
        split (t->l, l, t->l, key, add),  r = t;
    else
        split (t->r, t->r, r, key, add + 1 + cnt(t->l)),  l = t;
    upd_cnt (t);
    upd_soma (t);
}


void merge (pnode & t, pnode l, pnode r) {
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
    upd_cnt (t);
	upd_soma (t);
}

void insert(pnode & t, int pos, int val) {
	pnode t1 = NULL, t2 = NULL;
	split(t, t1, t2, pos);
	merge(t1, t1, new node(val, rng()));
	merge(t, t1, t2);
}
// ------------------------------------------------------------------------------ 35343927739

int main() {
	pnode raiz = NULL;

	insert(raiz, 1, 4);
	insert(raiz, 2, 3);
	insert(raiz, 3, 2);
	insert(raiz, 4, 3);

	print(raiz);
	printf("soma da raiz = %d\n", soma(raiz));

	pnode t1 = NULL, t2 = NULL;

	split(raiz, t1, t2, 2);
	printf("t1: %d\n", soma(t1));
	print(t1);
	printf("t2: %d\n", soma(t2));
	print(t2);

	
	return 0;
}
