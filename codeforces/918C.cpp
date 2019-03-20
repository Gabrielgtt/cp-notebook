#include <bits/stdc++.h>
#define MAXN 5002
using namespace std;

int dp[MAXN][MAXN], rest[MAXN][MAXN];
string frase;

bool valido(char left, char right){
	return (left == '?' && right == ')' || left == '(' && right == '?' || left == '?' && right == '?' || left == '(' && right == ')');
}

int resto(char left, char right){
	if (left == '(' && right == '(') return 2;
	if (left == ')' && right == ')') return 2;
	return 0;
}

bool aux(int l, int r){
	if (abs(l - r) <= 4) return true;
	return dp[l+2][r-2];
}

int main(){
	cin >> frase;

	int len = frase.size(), l = 0, r = 1, tam = 1, res = 0;

	while (tam <= len){
		while (r < len){
			// printf(".... l = %d, r = %d\n", l, r);
			if (valido(frase[l], frase[r]) && (dp[l+1][r-1] || l + 1 == r || resto(frase[l], frase[r]) == rest[l+1][r-1])) {
				res++;
				dp[l][r] = 1;
				printf(">> l = %d, r = %d\n", l, r);
			} else {
				rest[l][r] = resto(frase[l], frase[r]) + ((l + 1 == r) ? 0 : rest[l+1][r-1]);
				printf("l = %d, r = %d\n", l, r);
				printf("%d %d\n", resto(frase[l], frase[r]), rest[l][r]);
			}

			l++; r++;
		}
		tam+=2;
		l = 0; r = l + tam;
	}

	printf("%d\n", res);

	return 0;
}