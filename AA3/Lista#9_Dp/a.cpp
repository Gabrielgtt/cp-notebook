#include <bits/stdc++.h>
#define ll long long
#define MAXN 70
using namespace std;

ll m, k;
ll dp[MAXN][MAXN][2];
string numero;

void convert(ll num){
	if (num == 0) return;
	convert(num >> 1);
	numero += '0' + (num & 1);
}

ll solve(int index, int uns, bool flag){
	if (dp[index][uns][flag] != -1) return dp[index][uns][flag];

	if (index == numero.size() || uns == 0) return dp[index][uns][flag] = (uns == 0);

	if (flag || numero[index] == '1'){
		return dp[index][uns][flag] = solve(index+1, uns - 1, flag) + solve(index+1, uns, true);
	}

	return dp[index][uns][flag] = solve(index+1, uns, flag);
}

ll tenta(ll num){
	numero = "";
	convert(num);
	memset(dp, -1, sizeof dp);
	return solve(0, k, false);
}

int main(){
	scanf("%lld %lld", &m, &k);

	ll left = 1, right = 1000000000000000000;
	ll res, mid;
	while (left <= right){
		mid = (left+right) >> 1;

		res = tenta(mid << 1) - tenta(mid);

		if (res == m){
			break;
		} else if (res < m){
			left = mid+1;
		} else if (res > m){
			right = mid-1;
		}
	}

	printf("%lld\n", mid);
	return 0;
}