#include <bits/stdc++.h>
#define MAXN 100100
#define convert(a) a == 0 ? 0 : a < 0 ? -1 : 1
using namespace std;

int n, queries, arr[MAXN], SegTree[MAXN*4];

int query(int node, int start, int end, int left, int right){
	
	if (left > end || right < start) return 1;
	
	if (left <= start && right >= end){
		return SegTree[node];
	}

	int mid = (start+end)/2;

	int p1 = query(node*2, start, mid, left, right);  
	int p2 = query(node*2+1, mid+1, end, left, right);  

	return p1*p2;
}

void update(int node, int index, int value, int start, int end){
	if (start == end){
		arr[index] = value;
		SegTree[node] = convert(value);

	} else {
		int mid = (start+end)/2;

		if (start <= index && index <= mid){
			update(node*2, index, value, start, mid);
		} else {
			update(node*2+1, index, value, mid+1, end);
		}

		SegTree[node] = SegTree[node*2] * SegTree[node*2+1];
	}
}

void consST(int node, int start, int end){
	if (start == end){
		SegTree[node] = convert(arr[start]); 
	} else {
		int mid = (start+end)/2;
		consST(node*2, start, mid);
		consST(node*2+1, mid+1, end);
		SegTree[node] =  SegTree[node*2] * SegTree[node*2+1];
	}
}


int main(){

	while (cin >> n >> queries){

		// for (int i=0; i<(n*4); i++){ 
		// 	SegTree[i] = 1;
		// }

		for (int i=0; i<n; i++){
			cin >> arr[i];
		}

		consST(1, 0, n-1);
		
		char tipo;
		int l, r, v, index, res;
		for (int i=0; i<queries; i++){
			cin >> tipo;

			if (tipo == 'C') {
				cin >> index >> v;
				update(1, index-1, v, 0, n-1);
			} else {
				cin >> l >> r;
				res = query(1, 0, n-1, l-1, r-1);
				printf("%c", res == 0 ? '0' : res < 0 ? '-' : '+');
			}
		}
		printf("\n");
	}

	return 0;
}