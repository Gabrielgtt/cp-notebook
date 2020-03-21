#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

struct No {
	int v;
	No(int v_ = 0) : v(v_) {}
	No operator+(const No &o) const {
		return No(v+o.v);
	}
};

template <typename S>
struct Seg {
	int n;
	vector <S> t;

	// O(n) - build the seg tree
	Seg(No arr[], int n_) : n(n_) {
		t.resize(2*n);
		for (int i=0; i<n; i++) t[n+i] = arr[i];
		for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
	}

	void mod(int p, const S& value) {
		for (t[p += n] = value; p >>= 1; ) t[p] = t[p<<1] + t[p<<1|1];
	}

	S q(int l, int r) {
		S resl, resr;
		for (l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
			if (l&1) resl = resl + t[l++];
			if (r&1) resr = t[--r] + resr;
		}
		return resl + resr;
	}
};

int main() {
  int n = 10;
  No arr[n];
  for (int i=0; i<n; i++) arr[i] = No(i);
  Seg <No> seg(arr, n);
  assert(seg.q(3, 5).v == 12);
  assert(seg.q(7, 9).v == 24);
  return 0;
}

