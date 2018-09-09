#include <bits/stdc++.h>
#define MAXN 100010
#define ll long long
using namespace std;

int n, f;
ll caps[MAXN];

ll soma(ll num){
	ll res = 0;
	for (int i=0; i<n; i++){
		res += (num / caps[i]);
	}
	return res;
}

int main(){
	scanf("%d %d", &n, &f);

	for (int i=0; i<n; i++){
		scanf("%lld", &caps[i]);
	}

	ll left = 1, right = 1e9 + 7;

	ll res = 1;
	while (left <= right){
		ll mid = (left + right) / 2;

		ll s = soma(mid);  

		if (s >= f){
			right = mid-1;
			res = mid;
			
		} else if (s < f){
			left = mid+1;

		}
	}

	printf("%lld\n", res);
	return 0;
}