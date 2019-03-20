#include <bits/stdc++.h>
#define MAXN 300210
#define MAXLOG 22
using namespace std;

int arr[MAXN], gcdTable[MAXLOG][MAXN], minTable[MAXLOG][MAXN], n, logs[MAXN];
vector <int> lefts[MAXN];

int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}

void buildTableGcd(){
	for (int i = 0; i < n; i++){
		gcdTable[0][i] = arr[i];
	}

	for (int i = 1; (1 << i) <= n; i++){
		for (int j = 0; (j + (1 << i)) <= n; j++){
			gcdTable[i][j] = gcd( gcdTable[i-1][j], gcdTable[i-1][j + (1 << (i-1))]);
		}
	}
}

void buildTableMin(){
	for (int i = 0; i < n; i++){
		minTable[0][i] = arr[i];
	}

	for (int i = 1; (1 << i) <= n; i++){
		for (int j = 0; (j + (1 << i)) <= n; j++){
			minTable[i][j] = min( minTable[i-1][j], minTable[i-1][j + (1 << (i-1))]);
		}
	}
}

int solve(int tam){
	int mini, gcdi, logi = logs[tam]; 
	for (int i=0; i + tam <= n; i++){
		gcdi = gcd(gcdTable[logi][i], gcdTable[logi][i + tam - (1 << logi)] );
		mini = min(minTable[logi][i], minTable[logi][i + tam - (1 << logi)] );
		if (gcdi == mini){
			lefts[tam].push_back(i);
		}
	}
	return lefts[tam].size();
}

int main(){
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	buildTableMin();
	buildTableGcd();

	logs[0] = 0;
	logs[1] = 0;
	for (int i=2; i<=n; i++){
		logs[i] = logs[i >> 1] + 1;
	}

	int l = 1, r = n, maior = 1, mid;

	while (l <= r){
		mid = (r + l) / 2;
		if (solve(mid)){
			l = mid+1;
			if (mid > maior) maior = mid;
		} else {
			r = mid;
			if (l == r){
				solve(l);
				break;
			}
		}
	}

	printf("%d %d\n", lefts[maior].size(), maior-1);
	for (int i=0; i<lefts[maior].size(); i++){
		if (i != 0) printf(" ");
		printf("%d", lefts[maior][i]+1);
	}
	printf("\n");

	return 0;
}
