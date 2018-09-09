#include <bits/stdc++.h>
#define MAXN 120
using namespace std;

int matrix[MAXN][MAXN], res = 0, vis[MAXN][MAXN];
int n;

void solve(int i, int j){
	if (vis[i][j]) return;
	vis[i][j] = 1;
	res++;

	if (j+1 < n && matrix[i][j] <= matrix[i][j+1]){
		solve(i, j+1);
	} 
	if (i+1 < n && matrix[i][j] <= matrix[i+1][j]){
		solve(i+1, j);
	} 
	if (j-1 >= 0 && matrix[i][j] <= matrix[i][j-1]){
		solve(i, j-1);
	} 
	if (i-1 >= 0 && matrix[i][j] <= matrix[i-1][j]){
		solve(i-1, j);
	}
}

int main(){
	int c1, c2;
	scanf("%d", &n);
	scanf("%d %d", &c1, &c2);

	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			scanf("%d", &matrix[i][j]);
		}
	}

	solve(c1-1, c2-1);

	printf("%d\n", res);

	return 0;
}