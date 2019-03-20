#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define MAXN 2010
using namespace std;

string a, b;
int m, len;
char d;
ll dp[MAXN][MAXN][2];

ll addDigit(ll modulo, char digit){
	modulo = (modulo * (10 % m)) % m;
	modulo = (modulo + ((digit-'0') % m)) % m;
	return modulo;
}

ll solve(int pos, ll modulo, bool flag, const string &num){
	if (dp[pos][modulo][flag] != -1) return dp[pos][modulo][flag];
		
	if (pos == num.size()) return dp[pos][modulo][flag] = (modulo == 0);

	if (pos & 1){
		if (d <= num[pos] || flag){
			return dp[pos][modulo][flag] = solve(pos+1, addDigit(modulo, d), (d < num[pos]) || flag, num);
		}
		return dp[pos][modulo][flag] = 0;
	}

	dp[pos][modulo][flag] = 0;	
	for (char i = (pos == 0) ? '1' : '0'; i <= '9'; i++){ 
		if (i == d) continue;
		if (flag){
			dp[pos][modulo][flag] += solve(pos+1, addDigit(modulo, i), true, num) % MOD;
			dp[pos][modulo][flag] %= MOD;
			
		} else {
			if (i > num[pos]) break;
			dp[pos][modulo][flag] += solve(pos+1, addDigit(modulo, i), i < num[pos], num) % MOD;
			dp[pos][modulo][flag] %= MOD;

		}
	}
	return dp[pos][modulo][flag];
}


ll gogogo(){
	memset(dp, -1, sizeof dp);
	ll resA = solve(0, 0, false, a);

	memset(dp, -1, sizeof dp);
	ll resB = solve(0, 0, false, b);
	return ((resB - resA) + MOD) % MOD;
}

ll gamb(){
	int mod = 0;
	for (int i=0; i<a.size(); i++){
		mod = (mod * (10 % m)) % m;
		mod = (mod + ((a[i]-'0') % m)) % m;
	}
	if (mod != 0) return 0; 
	for (int i=0; i<a.size(); i++){
		if (i & 1 && a[i] != d) return 0;
		if (!(i & 1) && a[i] == d) return 0;
	}
	return 1;
}

int main(){
	cin >> m >> d;
	cin >> a >> b;
	cout << (gogogo() + gamb()) % MOD << endl;

	return 0;
}