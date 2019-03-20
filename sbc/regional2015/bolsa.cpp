#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int INF = 1e9;
const int MAXN = 200010;

ll dp[MAXN][2];
ll custo[MAXN];
int n, c;

ll solve(int idx, bool gasto){
	if (dp[idx][gasto] != -1) return dp[idx][gasto];
	if (idx == n) return 0;

	ll res = solve(idx+1, gasto);
		
	if (gasto){
		res = max(res, solve(idx+1, false) + custo[idx]);

	} else {
		res = max(res, solve(idx+1, true) - custo[idx] - c);
	}

	return dp[idx][gasto] = res;
}

int main(){
	scanf("%d %d", &n, &c);
	memset(dp, -1, sizeof dp);
	for (int i=0; i<n; i++){
		scanf("%d", &custo[i]);
	}

	printf("%lld\n", solve(0, false));
	return 0;
}