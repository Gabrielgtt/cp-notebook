#include <bits/stdc++.h>
#define MAXN 10020
using namespace std;

bool comp(int a, int b){
	return a > b;
}

int main(){
	int n;
	scanf("%d", &n);

	int m, arr[MAXN], ori[MAXN];
	while (n--){
		scanf("%d", &m);

		for (int i=0; i<m; i++){
			scanf("%d", &arr[i]);
			ori[i] = arr[i];
		}

		sort(arr, arr+m, comp);

		int res = 0;
		for (int i=0; i<m; i++){
			if (arr[i] == ori[i]) res++;
		}		
		printf("%d\n", res);
	}

	return 0;
}