#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
#define MAXLOG 100010
using namespace std;

int lca[MAXLOG][MAXN];



int main(){

	for (int j=1; j<MAXLOG; j++){
		for (int i=1; i<=n; i++){
			lca[i][j] = lca[lca[i][j-1]][j-1];
		}
	}

	for (int j=1; j<MAXNLOG; j++){
		for (int i=0; i + (1 << j) < n; i++){
			sparse[i][j] = max(sparse[i][j-1], sparse[i+(1 << (j-1))][j-1]);
		}
	}

	return 0;
}