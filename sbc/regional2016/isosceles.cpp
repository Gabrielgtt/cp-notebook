#include <bits/stdc++.h>
using namespace std;

const int MAXN = 600000;

int l[MAXN], r[MAXN], arr[MAXN];

int main(){
	int n;
	scanf("%d", &n);

	for (int i=1; i<=n; i++){
		scanf("%d", &arr[i]);
		l[i] = min(arr[i], l[i-1]+1);
	}

	int res = 1;
	for (int i=n; i>0; i--){
		r[i] = min(arr[i], r[i+1]+1);
		res = max(res, min(r[i], l[i]));
	}

	printf("%d\n", res);

	return 0;
}