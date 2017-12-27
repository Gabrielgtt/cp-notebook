#include <bits/stdc++.h>

using namespace std;

int main(){
	int num; scanf("%d", &num);

	for (int i=1; i<=num; i++){
		int n, a, res;
		scanf("%d", &n);
		int mod = (n/2)+1;

		for (int j=1; j<=n; j++){
			scanf("%d", &a);
			if (j == mod) res = a;
		}

		printf("Case %d: %d\n", i, res);
	}



	return 0;
}