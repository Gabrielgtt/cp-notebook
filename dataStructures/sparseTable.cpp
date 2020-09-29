#include <bits/stdc++.h>
#define MAXN 600000
#define MAXLOG 22
#define INF 1e9
using namespace std;

// ------------------------------------------------------------------------------ 
int logs[MAXN];
template <typename T>
struct St {
	vector<vector<T>> table;
	// O(n*log(n)) - Build table from arr of size n
	St(T arr[], int n) { 
		logs[0] = logs[1] = 0;
		for (int i=2; i<n; i++) logs[i] = logs[i/2]+1;
		int lo = logs[n-1]+1;
		table.resize(lo, vector<T>(n));
		for (int i=0; i<n; i++) table[0][i] = arr[i];
		for (int j=1; j<lo; j++)
			for (int i=0; i+(1<<j)<=n; i++)
				table[j][i] = min(table[j-1][i], table[j-1][i+(1<<(j-1))]);
	}
	// O(1) - Query [l..r]
	T query(int l, int r) { 
		if (l > r) swap(l, r);
		return min(table[logs[r-l]][l], table[logs[r-l]][r - (1 << logs[r-l]) + 1]);
	}
};
// ------------------------------------------------------------------------------

int main() {
	int arr[10] = {1, 2, 3, -6, 1, 2, -2, 3, 4, 5};
	St <int> tb(arr, 10);
	assert(tb.query(1, 6) == -6);
	assert(tb.query(0, 2) == 1);
	assert(tb.query(7, 9) == 3);
	assert(tb.query(9, 9) == 5);
	return 0;
}
