#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx,tune=native")
#define MAXN 400010
using namespace std;

int lazy[MAXN];

struct tree{
	int homi, fante, rato;
} st[MAXN];

tree tneutra;

void doLazy(int node, int start, int end){
	if (start != end) {
		lazy[node*2] += lazy[node];
		lazy[node*2] %= 3;
		lazy[node*2+1] += lazy[node];
		lazy[node*2+1] %= 3;
	}

	while (lazy[node] > 0) {
		swap(st[node].homi, st[node].rato);
		swap(st[node].fante, st[node].rato);
		lazy[node] -= 1;
	}	

}

void updateRange(int node, int start, int end, int left, int right){
	if (lazy[node] != 0){
		doLazy(node, start, end);
	}

	if (start > end || start > right || end < left) return;

	if (start >= left && end <= right){
		swap(st[node].homi, st[node].rato);
		swap(st[node].fante, st[node].rato);

		if (start != end){
			lazy[node*2]++;
			lazy[node*2] %= 3;
			lazy[node*2+1]++;
			lazy[node*2+1] %= 3;
		}

		return;
	}

	int mid = (start + end) / 2;

	updateRange(node*2, start, mid, left, right);
	updateRange(node*2+1, mid+1, end, left, right);

	st[node].homi = st[node*2].homi + st[node*2+1].homi; 
	st[node].fante = st[node*2].fante + st[node*2+1].fante; 
	st[node].rato = st[node*2].rato + st[node*2+1].rato;
}

tree queryRange(int node, int start, int end, int left, int right){
	if (start > end || right < start || end < left){
		return tneutra;
	}

	if (lazy[node] != 0){
		doLazy(node, start, end);
	}

	if (left <= start && end <= right){
		return st[node];
	}

	int mid = (start+end)/2;

	tree p1 = queryRange(node*2, start, mid, left, right);
	tree p2 = queryRange(node*2+1, mid+1, end, left, right);
	tree res;
	res.homi = p1.homi + p2.homi;
	res.fante = p1.fante + p2.fante;
	res.rato = p1.rato + p2.rato;

	return res;
}

void construct(int node, int start, int end){
	if (start == end){
		st[node].homi += 1;
	} else {
		int mid = (start + end)/2;

		construct(node*2, start, mid);
		construct(node*2+1, mid+1, end);

		st[node].homi = st[node*2].homi + st[node*2+1].homi;
	}
}

int main(){
	int n, m, l, r;
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	char tipo;

	while (cin >> n >> m){

		memset(st, 0, sizeof st);
		memset(lazy, 0, sizeof lazy);

		construct(1, 0, n-1);

		while (m--){
			cin >> tipo >> l >> r;

			if (tipo == 'M'){
				updateRange(1, 0, n-1, l-1, r-1);

			} else {
				tree res = queryRange(1, 0, n-1, l-1, r-1);
				printf("%d %d %d\n", res.homi, res.fante, res.rato);
			}
		}
		
		printf("\n");
	}

	return 0;
}