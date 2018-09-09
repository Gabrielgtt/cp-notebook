#include <bits/stdc++.h>
#define MIN -1000000001
#define MAXN 100010
using namespace std;

int arr[MAXN], tree[MAXN*4];

void updateTree(int node, int start, int end, int value, int index){
	if (start == end){
		tree[node] = value;

	} else {
		int mid = (start+end)/2;

		if (index <= mid){
			updateTree(node*2, start, mid, value, index);
		} else {
			updateTree(node*2+1, mid+1, end, value, index);
		}

		tree[node] = max(tree[node*2], tree[node*2+1]);
	}
}

void constructTree(int node, int start, int end){
	if (start == end){
		tree[node] = arr[start];
	} else {
		int mid = (start+end)/2;

		constructTree(node*2, start, mid);
		constructTree(node*2+1, mid+1, end);

		tree[node] = max(tree[node*2], tree[node*2+1]);
	}
}

int query(int node, int start, int end, int left, int right){
	if (right < start || end < left){
		return MIN;
	}

	if (left <= start && end <= right){
		return tree[node];
	}

	int mid = (start+end)/2;

	return max(query(node*2, start, mid, left, right), query(node*2+1, mid+1, end, left, right));
}

int main(){
	int t, n, ballons;


	scanf("%d", &t);

	for (int j=0; j<t; j++){
		if (j>0) printf("\n");
		printf("Testcase %d:\n", j);

		scanf("%d %d", &n, &ballons);

		int aux;
		for (int i=0; i<n; i++){
			scanf("%d", &aux);
			arr[i] = aux;
		}

		constructTree(1, 0, n-1);

		int q, l, r, v, index;
		char tipo;

		scanf("%d", &q);

		for (int i=0; i<q; i++){
			cin >> tipo;

			if (tipo == 'A'){
				scanf("%d", &v);
				ballons += v;

			} else if (tipo == 'B'){
				scanf("%d %d", &index, &v);
				updateTree(1, 0, n-1, v, index);

			} else if (tipo == 'C'){
				scanf("%d %d", &l, &r);
				int res = query(1, 0, n-1, l, r);
				printf("%d\n", abs(ballons - res));
			}
		}

	}
}