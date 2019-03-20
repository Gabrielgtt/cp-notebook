#include <bits/stdc++.h>
#define MAXN 30
#define ll long long
using namespace std;

bool ban[12];
ll dp[MAXN][3][3];
string num;
int n;

ll solve(int index, bool flag, bool beg){
	if (dp[index][flag][beg] != -1) return dp[index][flag][beg];
	if (index == n) return dp[index][flag][beg] = beg;

	ll res = 0;
	int atual = (num[index] - '0');
	for (int i = 0; i <= 9; i++){
		if (ban[i]) continue;
		if (!flag && i > atual) break;

		res += solve(index+1, (i < atual) || flag, true);
	}

	if (ban[0] && !beg) res += solve(index+1, true, false);

	return dp[index][flag][beg] = res;
}

int main(){
	// int t = 6; 
	// eof:

	for (int i=0; i<10; i++){
		scanf("%d", &ban[i]);
	}

	memset(dp, -1, sizeof dp);

	ll gamb;
	cin >> gamb;
	gamb--;
	num = to_string(gamb);
	n = num.size();

	printf("%lld\n", solve(0, false, false));

	// printf("%lld\n", dp[1][false]);

	// if(--t) goto eof;

	return 0;
}


// 0
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8
// 9
// 10
// 11
// 12
// 13
// 14
// 15
// 16
// 17
// 18
// 19
// 20
// 21
// 22
// 23
// 24
