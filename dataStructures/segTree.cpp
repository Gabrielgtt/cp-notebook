#include <bits/stdc++.h>
#define MAXN 1000000
#define INF 1e9
using namespace std;

// Segtree de maximo
int n;
int seg[MAXN];

// ------------------------------------------------------------------------------
int query(int ql, int qr, int l = 0, int r = n-1, int node = 1) {
	if (qr < l || r < ql) return -INF;
	if (ql <= l && r <= qr) return seg[node];
	int mid = (l+r)>>1;
	int left = query(ql, qr, l, mid, node*2);		
	int right = query(ql, qr, mid+1, r, node*2+1);		
	return max(left, right);
}

void update(int idx, int valor, int l = 0, int r = n-1, int node = 1) {
	if (l == r) {
		seg[node] = valor;
	} else {
		int mid = (l+r)>>1;
		if (idx <= mid) update(idx, valor, l, mid, node*2);
		else update(idx, valor, mid+1, r, node*2+1);
		seg[node] = max(seg[node*2], seg[node*2+1]);
	}
}

void build(int array[], int l = 0, int r = n-1, int node = 1) {
	if (l == r) {
		seg[node] = array[l];
	} else {
		int mid = (l+r)>>1;
		build(array, l, mid, node*2);
		build(array, mid+1, r, node*2+1);
		seg[node] = max(seg[node*2], seg[node*2+1]);
	}
}
// ------------------------------------------------------------------------------ 23763770108

int main () {
	int arr[10] = {1, -2, 4, 5, 34, 0, -23, 3, 25, -5};
	n = 10;
	build(arr);
	assert(query(0, 3) == 5);
	update(0, 12);
	assert(query(0, 4) == 34);
	return 0;
}
