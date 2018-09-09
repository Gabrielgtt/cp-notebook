#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 100010;

ll arr[MAXN];
int n;

void solve(){
	set <ll> nums;

	for (int i=0; i<n; i++){
		scanf("%lld", &arr[i]);
		arr[i] += i == 0 ?  0 : arr[i-1];
		nums.insert(arr[i]);
	}

	ll total = arr[n-1];
	ll pulo = arr[n-1] / (ll) 3;

	if (total % 3 != 0){
		printf("0\n");
		return;
	}

	ll res = 0;
	for (int i=0; i<n; i++){
		if (nums.count(arr[i]) && nums.count((arr[i]+pulo) % total) &&
			nums.count((arr[i]+pulo+pulo) % total)) {
			res++;
			nums.erase(arr[i]);
			nums.erase((arr[i]+pulo) % total);
			nums.erase((arr[i]+pulo+pulo) % total);
		}
	}
	printf("%lld\n", res);	
}

int main(){

	while (scanf("%d", &n) != EOF){
		solve();
	}

	return 0;
}