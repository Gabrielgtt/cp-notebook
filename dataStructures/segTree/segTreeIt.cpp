/*
Range update, single query, COMUTATIVE
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

template <typename T>
struct Seg {
	int n;
	vector <T> t;

	// O(n) - build the seg tree
	Seg(T arr[], int n_) : n(n_) {
		t.resize(2*n);
		for (int i=0; i<n; i++) t[n+i] = arr[i];
		for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
	}

	// O(logn) - set value at position p
	void mod(int p, T value) {  
		for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
	}

	// O(logn) - sum on interval [l, r]
	T q(int l, int r) {  
		T res = 0;
		for (l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
			if (l&1) res += t[l++];
			if (r&1) res += t[--r];
		}
		return res;
	}
};

/* VERSÃO SECA
const int N = 1e5;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) {  // sum on interval [l, r]
  int res = 0;
  for (l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}
*/

int main() {
  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  Seg <int> seg(arr, 10);
  seg.mod(3, 1);
  assert(seg.q(3, 5) == 12);
  assert(seg.q(7, 9) == 27);
  return 0;
}

