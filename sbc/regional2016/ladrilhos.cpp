#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

const int MAXN = 600;

int ma[MAXN][MAXN];
bool v[MAXN][MAXN];

int a1[] = {1, 0, -1, 0};
int a2[] = {0, 1, 0, -1};

int solve(int x, int y){
	int res = 1;
	v[x][y] = true;
	for (int i=0; i<4; i++){
		int xx = x + a1[i]; 
		int yy = y + a2[i]; 
		if (ma[xx][yy] == ma[x][y] && !v[xx][yy]){
			res += solve(xx, yy);
		}
	}
	return res;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	memset(ma, -1, sizeof ma);

	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			scanf("%d", &ma[i][j]);
		}
	}

	int res = 1e9;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			if (!v[i][j]){
				res = min(res, solve(i, j));
			}
		}
	}
	printf("%d\n", res);
	return 0;
}