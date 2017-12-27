#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);

	int n1, n2;

	int res = 0, num;
	for (int i=1; i<=n; i++){
		scanf("%d", &num);
		if (tala[num] == 0){
			tala[i] += 1;
			res++;

		} else {
			tala[num] -= 1;
			tala[i] += 1;
		}
	}

	printf("%d\n", res);

	return 0;
}