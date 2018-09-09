#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;

long long arr[MAXN], n, bit[10000010], maior;

void update(long long value, int index){
	while (index <= maior){
		bit[index] += value;
		index += (index & (-index));
	}
}

long long soma(int index){
	long long res = 0;
	while (index > 0){
		res += bit[index];
		index -= (index & (-index));
	}
	return res;
}

long long inversions(){
	for (int i=0; i<=maior; i++){
		bit[i] = 0;
	}
	long long invers = 0;
	for (int i=n-1; i>=0; i--){
		invers += soma(arr[i]-1);
		update(1, arr[i]);
	}
	return invers;
}

int main(){
	int t;
	scanf("%d", &t);

	for (int i=0; i<t; i++){
		scanf("%d", &n);
		maior = -10000001;
		for (int i=0; i<n; i++){
			scanf("%d", &arr[i]);
			if (arr[i] > maior) maior = arr[i];
		}
		printf("%lld\n", inversions());
	}

	return 0;
}