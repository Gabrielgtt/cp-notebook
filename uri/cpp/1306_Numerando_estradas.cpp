#include <bits/stdc++.h>

using namespace std;

int main(){
	int a, b, aux=1;

	scanf("%d %d", &a, &b);
	while (a != 0){
		printf("Case %d: ", aux); aux++;
		int res = 0;
		if (a % b == 0){
			res = (a/b)-1;
			if (res > 26) printf("impossible\n");
			else printf("%d\n", res);
		} else {
			res = (a/b);
			if (res > 26) printf("impossible\n");
			else printf("%d\n", res);
		}


		scanf("%d %d", &a, &b);
	}

	return 0;
}