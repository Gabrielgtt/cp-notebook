#include <bits/stdc++.h>
#define MAXN
#define ll long long
#define ii pair <int, int>
#define f first
#define s second
#define pb push_back
using namespace std;

int main(){
	int n;
	scanf("%d", &n);

	ll q;
	for (int i=0; i<n; i++){
		scanf("%lld", &q);

		ll left = 0;
		ll right = 2000000000;
		ll res = 0;

		while (left <= right){
			ll mid = (left+right)>>1;

			ll solve = (1LL + mid);

			if (solve & 1){
				solve *= mid >> 1;
			} else {
				solve >>= 1;
				solve *= mid;
			}

			if (solve <= q){
				left = mid + 1;
				res = mid;
			} else {
				right = mid - 1;
			}
		}

		printf("%lld\n", res);
	}

	return 0;
}