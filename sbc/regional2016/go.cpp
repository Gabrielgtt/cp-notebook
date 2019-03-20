#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

typedef pair <long long, long long> ii;
const int MAXN = 502;

ii acm[MAXN][MAXN];

int main(){
	int n, p;
	scanf("%d %d", &n, &p);

	int x, y;
	for (int i=0; i<p; i++){
		scanf("%d %d", &x, &y);
		acm[x][y].f = 1;
	}
	for (int i=0; i<p; i++){
		scanf("%d %d", &x, &y);
		acm[x][y].s = 1;
	}

	ll resP = p, resB = p;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			acm[i][j].f += acm[i-1][j].f + acm[i][j-1].f - acm[i-1][j-1].f;
			acm[i][j].s += acm[i-1][j].s + acm[i][j-1].s - acm[i-1][j-1].s;
		}
	}

	int pretas, brancas;
	for (int tam = 2; tam<=n; tam++){
		for (int i=tam; i<=n; i++){
			for (int j=tam; j<=n; j++){
				pretas = acm[i][j].f - acm[i-tam][j].f - acm[i][j-tam].f + acm[i-tam][j-tam].f;
				brancas = acm[i][j].s - acm[i-tam][j].s - acm[i][j-tam].s + acm[i-tam][j-tam].s;

				if (pretas == 0 && brancas > 0) resB++;
				if (brancas == 0 && pretas > 0) resP++;
			}
		}
	}

	printf("%lld %lld\n", resP, resB);

	return 0;
}