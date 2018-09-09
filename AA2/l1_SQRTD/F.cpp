#include <bits/stdc++.h>
#define MAXN 100010
#define SQRT 250
using namespace std;

int n, arr[MAXN], q, sqrtd[MAXN][SQRT];

void fillDp(int n){
	for (int k=1; k<=SQRT; k++){
		for (int index=n; index>0; index--){
			if (index+arr[index]+k > n) sqrtd[index][k] = 1;
			else sqrtd[index][k] = sqrtd[index+arr[index]+k][k] + 1;
		}
	}
}

int brutasso(int index, int k){
	int res = 0;
	while (index <= n) index += arr[index]+k, res++;
	return res;
}

int main(){

	scanf("%d", &n);
	for (int i=1; i<=n; i++) scanf("%d", &arr[i]);

	scanf("%d", &q);
	
	fillDp(n);

	int ind, k;
	while(q--){
		scanf("%d %d", &ind, &k);

		if (k <= SQRT) printf("%d\n", sqrtd[ind][k]);
		else printf("%d\n", brutasso(ind, k));
	}

	return 0;
}