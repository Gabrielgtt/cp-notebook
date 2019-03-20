#include <bits/stdc++.h>
#define MAXN 202010
#define ll long long
#define MOD 1000000007
#define debug_arr(arr, tam) cerr << #arr << " = "; for (int i=0; i<tam; i++) printf("%lld%c", arr[i], " \n"[i == tam-1])
using namespace std;

string grande, pequena, linha;

ll back[MAXN];
ll dp[MAXN], arr[MAXN], acm[MAXN], gamb[MAXN];
int n;

void kmp(){
	int len = pequena.size()+1;
	for (int i=1, j; i<n; i++){
		j = back[i-1];
		while(j > 0 && linha[i] != linha[j]) j = back[j-1];
		if (linha[i] == linha[j]) j++;
		back[i] = j;
		if (i >= len) arr[i-len] = j;
	}
}

ll soma(ll a, ll b){ return ( (a%MOD) + (b%MOD) ) % MOD;}
ll mult(ll a, ll b){ return ( (a%MOD) * (b%MOD) ) % MOD;}

int main(){
	ios::sync_with_stdio(false);

	cin >> grande >> pequena;

	if (pequena.size() > grande.size()){
		printf("0\n");
		return 0;
	}

	linha = pequena + "&" + grande;
	n = linha.size();

	kmp();

	int len = grande.size();
	int match = pequena.size();

	dp[0] = arr[0] == match;
	acm[0] = gamb[0] = dp[0];

	for (int i=1; i<len; i++){
		if (arr[i] == match){
			dp[i] = soma(dp[i], i+2-match);
			dp[i] = soma(dp[i], acm[i-match]);
			gamb[i] = dp[i];
			dp[i] = soma(dp[i], dp[i-1]);

		} else {
			if (acm[i-1]) {
				dp[i] = soma(dp[i-1], gamb[i-1]);
			}
			
			gamb[i] = gamb[i-1];
		}

		acm[i] = soma(dp[i], acm[i-1]);
	}

	printf("%lld", dp[len-1]);
	return 0;
}