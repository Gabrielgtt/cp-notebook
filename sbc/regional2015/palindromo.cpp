#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

const int MAXN = 2010;
typedef pair <int, int> ii;

char word[MAXN];
bool good[MAXN];
int n;

ii dp[MAXN][MAXN];

ii solve(int l, int r){
	if (dp[l][r] != ii(-1, -1)) return dp[l][r];

	int pontos = good[l] + good[r];
	ii res = ii(-1, -1);

	if (l == r)
		return dp[l][r] = ii(good[l], 1);

	if (word[l] == word[r] && l+1 == r)
		return dp[l][r] = ii(pontos, 2);

	if (word[l] == word[r]){
		res = solve(l+1, r-1);
		res.first += pontos;
		res.second += 2;
	}

	res = max(res, max(solve(l+1, r), solve(l, r-1)));
	return dp[l][r] = res;
}

int main(){
	scanf("%s", word);
	n = strlen(word);
	int m;
	scanf("%d", &m);

	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			dp[i][j] = ii(-1, -1);
		}
	}

	int num;
	for (int i=0; i<m; i++){
		scanf("%d", &num);
		good[--num] = true;
	}

	printf("%d\n", solve(0, n-1).second);
	return 0;
}