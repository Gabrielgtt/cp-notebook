#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------------------------
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

struct node {
    int v, prior;
    node * l, * r;
    node() { }
    node (int v, int prior) : v(v), prior(prior), l(NULL), r(NULL) { }
};
typedef node * pnode;

void print (pnode no) {
	if (!no) return;
	printf("%d\n", no->v);
	print(no->l), print(no->r);
}

void split (pnode t, int v, pnode & l, pnode & r) {
    if (!t)
        l = r = NULL;
    else if (v < t->v)
        split (t->l, v, l, t->l),  r = t;
    else
        split (t->r, v, t->r, r),  l = t;
}

void insert (pnode & t, pnode it) {
    if (!t)
        t = it;
    else if (it->prior > t->prior)
        split (t, it->v, it->l, it->r),  t = it;
    else
        insert (it->v < t->v ? t->l : t->r, it);
}

void merge (pnode & t, pnode l, pnode r) {
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
}
// ------------------------------------------------------------------------------ 22819149183

void erase (pnode & t, int v) {
    if (t->v == v)
        merge (t, t->l, t->r);
    else
        erase (v < t->v ? t->l : t->r, v);
}

pnode unite (pnode l, pnode r) {
    if (!l || !r)  return l ? l : r;
    if (l->prior < r->prior)  swap (l, r);
    pnode lt, rt;
    split (r, l->v, lt, rt);
    l->l = unite (l->l, lt);
    l->r = unite (l->r, rt);
    return l;
}

int main() {
	pnode raiz = NULL;

	insert(raiz, new node(12, rng()));
	insert(raiz, new node(6, rng()));
	insert(raiz, new node(8, rng()));
	insert(raiz, new node(7, rng()));
	insert(raiz, new node(9, rng()));

	pnode a, b, lixo;
	split(raiz, 7, a, b);
	printf("a: \n");
	print(a); // 6 7
	printf("b: \n");
	print(b); // 8 9 12
	erase(a, 7);
	merge(raiz, a, b);
	printf("raiz: \n");
	print(raiz); // 8 6 9 12
	return 0;
}
