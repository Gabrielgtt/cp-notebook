#include <bits/stdc++.h>
#define ll long long
#define MAXN 1000002
using namespace std;

int n;
int arr[MAXN];
ll dp[MAXN][9][2];

ll solve(int index, int mod, int cont){
	if (dp[index][mod][cont] != -1) return dp[index][mod][cont];
	if (index == n) return dp[index][mod][cont] = 0;

	int outro = (mod + arr[index]) % 8;

	dp[index][mod][cont] = solve(index+1, outro, 1) + (outro == 0);
	if (cont == 0) dp[index][mod][cont] += solve(index+1, 0, 0);

	return dp[index][mod][cont];
}

int main(){
	scanf("%d", &n);

	memset(dp, -1, sizeof dp);

	for (int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}

	printf("%lld\n", solve(0, 0, 0));

	return 0;
}