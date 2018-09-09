#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2010;

int arr[MAXN];
int soma[MAXN];
int dp[MAXN][MAXN];
int pulo[MAXN][2];
int n, c, t1, t2;

void pulos(){
	int j = 0, k = 0;
	for (int i=0; i<n*2; i++){
		while (j <= n*2 && (arr[j] - arr[i]) <= t1){
			j++;
		}		
		while (k <= n*2 && (arr[k] - arr[i]) <= t2){
			k++;
		}
		pulo[i][0] = j;
		pulo[i][1] = k;
	}
}

int doit(int idx, int beg){
	if (dp[idx][beg] != -1) return dp[idx][beg];
	if (idx >= 2*n || idx-beg >= n) return 0;

	int menor = doit(pulo[idx][0], beg) + t1;
	int maior = doit(pulo[idx][1], beg) + t2;
	
	dp[idx][beg] = min(menor, maior);

	if (beg < n-1) dp[idx][beg] = min(dp[idx][beg], doit(idx+1, idx+1));
	return dp[idx][beg];
}

void solve(){
	memset(soma, 0, sizeof soma);
	memset(arr, 0, sizeof arr);
	memset(dp, -1, sizeof dp);
	memset(pulo, 0, sizeof pulo);
	if (t1 > t2) swap(t1, t2);
	for (int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	for (int i=n; i<n+n; i++){
		arr[i] = arr[i-n] + c;
	}
	pulos();
	printf("%d\n", doit(0, 0));
}

int main(){
	while (scanf("%d %d %d %d", &n, &c, &t1, &t2) != EOF){
		solve();
	}
	return 0;
}