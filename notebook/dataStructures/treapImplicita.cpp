#include <bits/stdc++.h>
#define MAXN 300000
using namespace std;


typedef node * pnode;

struct node {
	int key, prior, value;
	pnode l, r;
	bool rev;
	item() {}
	item(int key, int prior, int value) : key(key), prior(prior), value(value), l(NULL), r(NULL) {}
}


int cnt (pnode t) {
    return t ? t->cnt : 0;
}

void upd_cnt (pnode t) {
    if (t)
        t->cnt = 1 + cnt(t->l) + cnt (t->r);
}

void split(pnode t, pnode &l, pnode &r, int key, int add = 0) {
	if (!t)
		return void(l = r = 0); // ?
	int cur_key = add + cnt(t->l);
	else if (key <= cur_key)
		split(t->l, l, t->l, key, add), r = t;
	else 
		split (t->r, t->r, r, key, add + 1 + cnt(t->l)),  l = t;
    upd_cnt (t);
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
	upd_cnt(t);
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

void push(pitem it) {
    if (it && it->rev) {
        it->rev = false;
        swap (it->l, it->r);
        if (it->l)  it->l->rev ^= true;
        if (it->r)  it->r->rev ^= true;
    }
}

void rodopia(pitem t, int l, int r) {
    pitem t1, t2, t3;
    split (t, t1, t2, l);
    split (t2, t2, t3, r-l+1);
    t2->rev ^= true;
    merge (t, t1, t2);
    merge (t, t, t3);
}

void shiftzera(pnode t, int de, int para){
	pnode t1, t2, t3, t4;
	push(t);
	split(t, t1, t2, de);
	split(t2, t2, t3, para-de+1);
	split(t2, t2, t4, para-de);
	merge(t, t1, t4);
	merge(t, t, t2);
	merge(t, t, t3);
}

int consulta(pnode t, int idx){
	pnode t1, t2;
	split(t, t1, t2, idx);

}

int arr[MAXN];

int main() {
	int n, q, m;
	scanf("%d %d %d", &n, &q, &m);

	pnode treap = new node(0);

	for (int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}

	int tipo, de, para;
	for (int i=0; i<q; i++){
		scanf("%d %d %d", &tipo, &de, &para);
		if (tipo == 1){
			shiftzera(treap, de, para);
		} else {
			rodopia(treap, de, para);
		}
	}

	for (int i=0; i<m; i++){
		scanf("%d", &de);
		printf("%d\n", consulta(de));
	}

	return 0;
}