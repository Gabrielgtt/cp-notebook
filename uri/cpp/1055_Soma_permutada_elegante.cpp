#include <bits/stdc++.h>
#define rep(i, a, b) for(int (i)=(a); (i)<(b); (i)++)
#define MAXI 55
using namespace std;

int n, nums, aux, arr[MAXI];

int elegantSum(){
	int maxSum = 0, value;

	for(int i=0; i<nums; i++) {
		value = 0;
		for(int j=i+1; j<nums; j++) {
			value = max(value, abs(arr[i]-arr[j]));
		}
		maxSum+=value;
	}

	return maxSum;
}

int main(){
	scanf("%d", &n);

	for(int i=0; i<n; i++) {
		scanf("%d", &nums);

		for(int j=0; j<nums; j++) scanf("%d", &arr[j]);

		printf("Case %d: %d\n", i+1, elegantSum());
	}

	return 0;
}