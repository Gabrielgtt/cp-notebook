#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define ii pair <int, int>
#define f first
#define s second
#define INF 1e9
#define MAXN 200010
#define MOD 1000000007
using namespace std;

ll mtx[MAXN][MAXN];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			scanf("%lld", &mtx[i][j]);
		}
	}

	int x, y;
	scanf("%d %d", &x, &y);

	ll limite = mtx[x][y];

		
	return 0;
}
