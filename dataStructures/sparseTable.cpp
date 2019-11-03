#include <bits/stdc++.h>
#define MAXN 600000
#define MAXLOG 22
#define INF 1e9
using namespace std;

// Sparse table de min

int n, logs[MAXN];
// ------------------------------------------------------------------------------ 
struct SparseTable {
	int table[MAXLOG][MAXN];

	void build(int array[]) {
		logs[0] = logs[1] = 0;
		for (int i = 2; i < MAXN; i++) logs[i] = logs[i/2]+1;
		for (int i = 0; i < n; i++) table[0][i] = array[i];
		for (int j = 1; j < MAXLOG; j++) {
			for (int i = 0; i + (1<<j) <= n; i++) {
				table[j][i] = min(table[j-1][i], table[j-1][i+(1<<(j-1))]);
			}
		}
	}

	int query(int l, int r) {
		if (l > r) swap(l, r);
		return min(table[logs[r-l]][l], table[logs[r-l]][r - (1 << logs[r-l]) + 1]);
	}
} tb;
// ------------------------------------------------------------------------------ 14631003288

int main() {
	int arr[10] = {1, 2, 3, -6, 1, 2, -2, 3, 4, 5};
	n = 10;
	tb.build(arr);
	assert(tb.query(1, 6) == -6);
	assert(tb.query(0, 2) == 1);
	assert(tb.query(7, 9) == 3);
	assert(tb.query(9, 9) == 5);
	return 0;
}
