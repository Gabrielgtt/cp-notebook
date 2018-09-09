#include <bits/stdc++.h>
#define MAXN 1000010
using namespace std;

int bit[MAXN], n, arr[MAXN], freqLeft[MAXN], freqRight[MAXN];
map <int, int> cont;

void update(int value, int index){
	while (index <= n){
		bit[index] += value;
		index += index & (-index);
	}
}

int getSum(int index){
	int res = 0;
	while (index > 0){
		res += bit[index];
		index -= index & (-index);
	}
	return res;
}

long long solve(){
	long long invers = 0;
	for (int i=n-1; i>=0; i--){
		invers += getSum(freqLeft[i]-1);
		update(1, freqRight[i]);
	}
	return invers;
}

int main(){
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}

	for (int i=0; i<n; i++){
		cont[arr[i]]++;
		freqLeft[i] = cont[arr[i]];
	}
	cont.clear();	
	for (int i=n-1; i>=0; i--){
		cont[arr[i]]++;
		freqRight[i] = cont[arr[i]];
	}

	printf("%lld\n", solve());

	return 0;
}