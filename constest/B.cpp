#include <bits/stdc++.h>
#define MAXN 11
#define INF 1e9
using namespace std;


int n, dp[110];
int main(){
	dp[1] = 1;
	dp[2] = 2;

	for (int i=3; i<=100; i++){
		dp[i] = i + dp[i-2];
	}
	int n;
	scanf("%d", &n);
	printf("%d\n", dp[n]);
	return 0;
}