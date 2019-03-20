#include <bits/stdc++.h>
#define MAXN 1010 
using namespace std;

int main(){
	int n, lim, aux, arr[MAXN], acm[MAXN];
	scanf("%d %d", &n, &lim);

	int subir = 0, descer = 0, mini = 1e9, maxi = -1;

	for (int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}

	int res = 0, dif1, minidif, dif2;
	for (int i=0; i<n-1; i++){
		dif1 = abs(lim-arr[i]);

		if (arr[i] < lim){
			arr[i] += dif1;
			arr[i+1] += dif1;
			res += dif1;
		} else if (arr[i] > lim){
			arr[i] -= dif1;
			arr[i+1] -= dif1;
			res += dif1;			
		}
	}
	
	printf("%d\n", res);

	return 0;
}