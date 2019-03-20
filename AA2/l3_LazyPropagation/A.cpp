#include <bits/stdc++.h>
#define MAXN 100010
#define ull unsigned long long int
using namespace std;

int n;

void updateBIT(ull BIT[], int i, int v){
	while (i <= n){
		BIT[i] += v;
		i += i & (-i);
	}
}

ull getSum(ull BIT[], int i){
	ull sum = 0;
	while (i > 0){
		sum += BIT[i];
		i -= i & (-i);
	}
	return sum;
}

ull sum(ull BIT1[], ull BIT2[], int i){
	return (getSum(BIT1, i) * i) - getSum(BIT2, i);
}

void updateRange(ull BIT1[], ull BIT2[], int l, int r, int v){
	updateBIT(BIT1, l, v);
	updateBIT(BIT1, r+1, -v);
	updateBIT(BIT2, l, v*(l-1));
	updateBIT(BIT2, r+1, -v*r);
}

ull rangeSum(ull BIT1[], ull BIT2[], int l, int r){
	return sum(BIT1, BIT2, r) - sum(BIT1, BIT2, l-1);
}

int main(){
	ull BIT1[MAXN], BIT2[MAXN];

	int t, q, tipo, l, r, v;
	scanf("%d", &t);


	while (t--){
		scanf("%d %d", &n, &q);
		memset(BIT1, 0, sizeof BIT1);
		memset(BIT2, 0, sizeof BIT2);

		while (q--){
			scanf("%d", &tipo);

			if (tipo == 0){
				scanf("%d %d %d", &l, &r, &v);
				updateRange(BIT1, BIT2, l, r, v);
			} else {
				scanf("%d %d", &l, &r);
				cout << rangeSum(BIT1, BIT2, l, r) << endl;
			}
		}
	}

	return 0;
}