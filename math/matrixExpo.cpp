#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1000000007;
const int MAXN = 51;

// ------------------------------------------------------------------------------ 
template <typename T>
T aux[MAXN][MAXN];

template <typename T>
struct maex {
	T so(T a, T b) { return (a + b) % MOD; }

	T mu(T a, T b) { return (a * b) % MOD; }

	void mu(T m1[][MAXN], T m2[][MAXN], int n) {
		memset(aux<T>, 0, sizeof aux<T>);
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				for (int z=0; z<n; z++)
					aux<T>[i][j] = so(aux<T>[i][j], mu(m1[i][z], m2[z][j]));
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				m1[i][j] = aux<T>[i][j];
	}

	maex(T m[][MAXN], T e, int n) {
		T ba[MAXN][MAXN];
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++) 
				ba[i][j] = m[i][j],
				m[i][j] = i == j ? 1 : 0;
		while (e) {
			if (e & 1) mu(m, ba, n);
			mu(ba, ba, n);
			e >>= 1;
		}
	}
};
// ------------------------------------------------------------------------------


int ma[MAXN][MAXN];
int main() {
	ma[0][0] = 1; // Fibo
	ma[0][1] = 1;
	ma[1][0] = 1;
	ma[1][1] = 0;
	maex <int> (ma, 6, 2);
	assert(ma[0][0] == 13);
	return 0;
}
