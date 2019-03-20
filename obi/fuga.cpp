#include <bits/stdc++.h>
#define MAXN 12
using namespace std;

int n, m;
int deX, deY;
int paraX, paraY;
int vis[MAXN][MAXN];

int c1[4] = {-2, 2, 0, 0};
int c2[4] = {0, 0, 2, -2};

bool check(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < m;
}

int dfs(int x, int y){
	if (x == paraX && y == paraY) return 1;
	vis[x][y] = true;

	int res = -1e9;
	for (int i=0; i<4; i++){
		int nx = x+c1[i];
		int ny = y+c2[i];

		if (!check(nx, ny) || vis[nx][ny]) continue;

		res = max(res, dfs(nx, ny) + 2);
	}

	vis[x][y] = false;

	return res;
}


int main(){
	scanf("%d %d", &n, &m);
	scanf("%d %d", &deX, &deY);

	scanf("%d %d", &paraX, &paraY);

	deX--; paraX--;
	deY--; paraY--;

	printf("%d\n", dfs(deX, deY));

	return 0;
}