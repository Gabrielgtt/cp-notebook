#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx,tune=native")
#define MAXN 1010
using namespace std;

int BIT[MAXN][MAXN], n, m;

void update(int x, int y, int value){
	for (int i = x; i <= n; i += (i & -i)){
		for (int j = y; j <= m; j += (j & -j)){
			BIT[i][j] += value;
		}	
	}
}

long long int getSum(int x, int y){
	long long int res = 0;
	for (int i = x; i > 0; i -= (i & -i)){
		for (int j = y; j > 0; j -= (j & -j)){
			res += BIT[i][j];
		}	
	}
	return res;
}

int main(){
	int p;
	char tipo;
	int x1, y1, q, x2, y2, v, aux;
	long long int res;

	while ((cin >> n >> m >> p) && n != 0){
		memset(BIT, 0, sizeof BIT);
		cin >> q;

		while(q--){
			cin >> tipo;

			if (tipo == 'A'){
				cin >> v >> x1 >> y1;
				update(x1+1, y1+1, v);
			} else {
				cin >> x1 >> y1 >> x2 >> y2;
				aux = x2;
				x2 = max(x1, x2);
				x1 = min(x1, aux);
				aux = y2;
				y2 = max(y1, y2);
				y1 = min(y1, aux);
				res = getSum(x2+1, y2+1) - getSum(x2+1, y1) - getSum(x1, y2+1) + getSum(x1, y1);
				cout << res*p << endl;
			}
		}
		cout << endl;
	}

	return 0;
}