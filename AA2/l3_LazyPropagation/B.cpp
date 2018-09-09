#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int n, acordes, temp[9], lazy[MAXN*4];

struct tree{
	int notas[9];
} st[MAXN*4];

tree neutra;

void rotate(int node, int v){
	memset(temp, 0, sizeof temp);

	for (int i = 0; i < 9; i++){
		temp[(i+v)%9] = st[node].notas[i];
	}

	for (int i = 0; i < 9; i++){
		st[node].notas[i] = temp[i];
	}	
}

void doLazy(int node, int start, int end){
	if (start != end){
		lazy[node*2] += lazy[node];
		lazy[node*2] %= 9;
		lazy[node*2+1] += lazy[node];
		lazy[node*2+1] %= 9;
	}

	rotate(node, lazy[node]);

	lazy[node] = 0;
}


void update(int node, int start, int end, int left, int right, int value){
	if (lazy[node] != 0) doLazy(node, start, end);

	if (start > end || start > right || end < left) return;

	if (left <= start && end <= right){
		rotate(node, value);

		if (start != end){
			lazy[node*2] += value;
			lazy[node*2] %= 9;
			lazy[node*2+1] += value;
			lazy[node*2+1] %= 9;
		}

		return;
	}

	int mid = (start + end) / 2;

	update(node*2, start, mid, left, right, value);
	update(node*2+1, mid+1, end, left, right, value);

	for (int i=0; i<9; i++){
		st[node].notas[i] = st[node*2].notas[i] + st[node*2+1].notas[i];
	}
}

tree maxRange(int node, int start, int end, int left, int right){
	if (start > end || start > right || end < left) return neutra;

	if (lazy[node] != 0) doLazy(node, start, end);

	if (left <= start && end <= right) return st[node];

	int mid = (start + end) / 2;

	tree p1 = maxRange(node*2, start, mid, left, right);
	tree p2 = maxRange(node*2+1, mid+1, end, left, right);

	tree res;
	for (int i=0; i<9; i++){
		res.notas[i] = p1.notas[i] + p2.notas[i];
	}

	return res;
}

void query(int node, int start, int end, int left, int right){
	if (lazy[node] != 0) doLazy(node, start, end);

	if (start == end){
		for (int i=0; i<9; i++){
			if (st[node].notas[i] != 0){
				printf("%d\n", i);
				return;
			}
		}
	}

	int mid = (start+end)/2;

	query(node*2, start, mid, left, right);
	query(node*2+1, mid+1, end, left, right);
}


void construct(int node, int start, int end){
	if (start == end){
		st[node].notas[1] += 1;

	} else {
		int mid = (start + end) / 2;

		construct(node*2, start, mid);
		construct(node*2+1, mid+1, end);

		st[node].notas[1] = st[node*2].notas[1] + st[node*2+1].notas[1];
	}	
}

int main(){
	scanf("%d %d", &n, &acordes);

	construct(1, 0, n-1);

	int l, r;
	while (acordes--){
		// printf("\nQuery %d\n", acordes+1);
		scanf("%d %d", &l, &r);

		tree res = maxRange(1, 0, n-1, l, r);

		int index = -1, maxi = -1;

		for (int i=0; i<9; i++){
			if (res.notas[i] >= maxi){
				maxi = res.notas[i];
				index = i;
			}
		}

		update(1, 0, n-1, l, r, index);
	}

	query(1, 0, n-1, 0, n-1);

	return 0;
}