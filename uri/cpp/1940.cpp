#include <bits/stdc++.h>
using namespace std;

int j, r, arr[300010], jog[300010];

int main(){
	scanf("%d %d", &j, &r);

	for (int i=0; i<r*j; i++){
		scanf("%d", &arr[i]);
	}

	int res=0, ind=0;
	for (int i=0; i<r*j; i++){
		jog[i%j] += arr[i];
		if (jog[i%j] >= res) res = jog[i%j], ind = (i%j)+1;
	}

	printf("%d\n", ind);

	return 0;
}