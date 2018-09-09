#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

int n, m;
int arr[1230122];
bool dp[MAXN][MAXN];
bool vis[MAXN][MAXN];
	
bool solve(int index, int mod){
	if (vis[index][mod]) return dp[index][mod];
	vis[index][mod] = true;
	if (index == n) return dp[index][mod] = false;

	int outro = (mod + arr[index]) % m;

	if (outro == 0) return dp[index][mod] = true;

	return dp[index][mod] = solve(index+1, outro) || solve(index+1, mod);
}

int main(){
	scanf("%d %d", &n, &m);

	memset(vis, 0, sizeof vis);

	for (int i=0; i<n; i++){
		scanf("%d", &arr[i]);
		arr[i] %= m;
	}

	if (n > m) {
		printf("YES\n");
	} else {
		printf("%s\n", solve(0, 0) ? "YES" : "NO");
	}

	return 0;
}