#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
using namespace std;

ll segTree[MAXN*4];
ll lazy[MAXN*4];

void doLazy(int node, int start, int end){
	if (start != end){
		lazy[node*2] += lazy[node];
		lazy[node*2+1] += lazy[node];	
	} 

	segTree[node] += (end - start + 1) * lazy[node];

	lazy[node] = 0;
}

void update(int node, int start, int end, int de, int para, ll valor){
	if (lazy[node] != 0) doLazy(node, start, end);

	if (start > end || end < de || start > para) return;

	if (de <= start && end <= para){
		lazy[node] = valor;
		doLazy(node, start, end);
		return;
	}

	int mid = (start+end)/2;

	update(node*2, start, mid, de, para, valor);
	update(node*2+1, mid+1, end, de, para, valor);

	segTree[node] = segTree[node*2] + segTree[node*2+1];
}

ll query(int node, int start, int end, int de, int para){
	if (start > end || end < de || start > para) return 0;

	if (lazy[node] != 0) doLazy(node, start, end);

	if (de <= start && end <= para){
		return segTree[node];
	}	

	int mid = (start+end)/2;

	return query(node*2, start, mid, de, para) +
		   query(node*2+1, mid+1, end, de, para);
}

int main(){
	int n, t;

	scanf("%d", &t);

	while(t--){
		memset(segTree, 0, sizeof segTree);
		memset(lazy, 0, sizeof lazy);

		int c;
		scanf("%d %d", &n, &c);

		int tipo, de, para;
		ll valor;

		for (int i=0; i<c; i++){
			scanf("%d", &tipo);

			if (tipo == 0){
				scanf("%d %d %lld", &de, &para, &valor);
				de--, para--;
				update(1, 0, n-1, de, para, valor);
			} else {
				scanf("%d %d", &de, &para);
				de--, para--;
				printf("%lld\n", query(1, 0, n-1, de, para));
			}
		}
	}

	return 0;
}