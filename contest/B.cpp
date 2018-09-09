#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define ii pair <int, int> 
#define MAXN 200010
#define MAXLOG 20
using namespace std;

ll arr[MAXN];

int main(){
	ll n, s;
	scanf("%lld %lld", &n, &s);

	for (int i=0; i<n; i++){
		scanf("%lld", &arr[i]);
	}

	sort(arr, arr+n);

	ll res = 0;

	if (s >= arr[n/2]){
		for (int i=n/2; i<n; i++){
			if (arr[i] >= s) break;
			res += s - arr[i];
		}		
		
	} else {
		for (int i=n/2; i>=0; i--){
			if (arr[i] <= s) break;
			res += arr[i] - s;
		}				
	}

	printf("%lld\n", res);

	return 0;
}
