#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define MAXN 1000
using namespace std;

// ------------------------------------------------------------------------------ 
ll soma(ll a, ll b) { return (a + b) % MOD; }

ll mult(ll a, ll b) { return (a * b) % MOD; }

ll aux[MAXN][MAXN];
void mult(ll m1[][MAXN], ll m2[][MAXN], int n) {
	memset(aux, 0, sizeof aux);
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			for (int z=0; z<n; z++)
				aux[i][j] = soma(aux[i][j], mult(m1[i][z], m2[z][j]));
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			m1[i][j] = aux[i][j];
}

void matrixExpo(ll m[][MAXN], ll e, int n) {
	if (e == 0) printf("retornar neutro!\n");
	e--;
	ll base[MAXN][MAXN];
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++) 
			base[i][j] = m[i][j];
	while (e) {
		if (e & 1) mult(m, base, n);
		mult(base, base, n);
		e >>= 1;
	}
}
// ------------------------------------------------------------------------------

