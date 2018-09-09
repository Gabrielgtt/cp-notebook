#include <bits/stdc++.h>
#define MAXN 200
using namespace std;


int main(){
	int n, m, arr[MAXN];
	scanf("%d %d", &n, &m);

	int num, total, res = 0;
	for (int i=0; i<n; i++){
		total = 0;
		for (int j=0; j<m; j++){
			scanf("%d", &num);
			if (num > 0) total++;
		}
		if (total == m) res++;
	}
	printf("%d\n", res);
	return 0;
}