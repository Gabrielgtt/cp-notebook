#include <bits/stdc++.h>
#define MAXN 70
#define ll long long
using namespace std;

char code[MAXN];
ll d, h, b;
string numero;
ll dp[MAXN][2][2];

ll solve(int index, bool flag, bool zerinho){
	if (dp[index][flag][zerinho] != -1) return dp[index][flag][zerinho];
	if (index == numero.size()) return dp[index][flag][zerinho] = (ll) zerinho;
		
	dp[index][flag][zerinho] = 0;
	for (int i=0; i<b; i++){
		if (i == 0 && code[0] == 'N'){
			if (!zerinho){
				dp[index][flag][zerinho] += solve(index+1, (i < (numero[index] - '0')) || flag, false);
			}

		} else {
			if (code[i] == 'S' && ((i <= (numero[index] - '0')) || flag)){
				dp[index][flag][zerinho] += solve(index+1, (i < (numero[index] - '0')) || flag, true);			
			}			
		}
	}
	return dp[index][flag][zerinho];
}

void convert(ll num){
	numero = "";
	if (num == 0) numero = "0";
	while (num > 0){
		numero += ('0' + (num % b));
		num /= b;
	}
	reverse(numero.begin(), numero.end());
}

ll tenta(ll num){
	memset(dp, -1, sizeof dp);
	convert(num);
	return solve(0, false, false);
}

int main(){
	while (true){
		scanf("%lld %lld %lld %s", &d, &h, &b, code);
		if (d == -1) break;

		printf("%lld\n", tenta(h) - tenta(d-1));
	}
	return 0;
}