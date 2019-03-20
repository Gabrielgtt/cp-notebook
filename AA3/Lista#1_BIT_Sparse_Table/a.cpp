#include <bits/stdc++.h>
#define MAXN 100010
#define MAXLOG 24
using namespace std;

int arr[MAXN], n, m, maxi[MAXLOG][MAXN], logs[MAXN];

void buildTable(){
	for (int i=0; i<n; i++){
		maxi[0][i] = arr[i];
	}

	for (int i=1; (1 << i) <= n; i++){
		for (int j=0; (j + (1 << i)) <= n; j++){
			maxi[i][j] = max(maxi[i-1][j], maxi[i-1][j + (1 << (i-1))]);
		}
	}
}

void fillLogs(){
	logs[0] = 0;
	logs[1] = 0;
	for (int i=2; i<=n; i++){
		logs[i] = logs[i >> 1] + 1;
	}
}

int main(){
	int x, y;
	scanf("%d", &n);

	for (int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	buildTable();
	fillLogs();

	scanf("%d %d %d", &m, &x, &y);

	long long res = 0;
	int dist, a, b;
	for (int i=0; i<m; i++){

		if (x > y) a = y, b = x;
		else b = y, a = x;

		dist = logs[b-a];
		res += max(maxi[dist][a], maxi[dist][b + 1 - (1 << dist)]);
		// printf("dist %d\n", dist);

		// printf("%d %d\n",b + 1 - (1 << dist), maxi[dist][b + 1 - (1 << dist)]);
		x = (x + 7) % (n-1);
		y = (y + 11) % n;
	}

	printf("%lld\n", res);

	return 0;
}
