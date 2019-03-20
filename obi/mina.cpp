#include <bits/stdc++.h>
#define iii pair <int, pair <int, int> > 
#define f first
#define s second
#define INF 1e9
#define MAXN 200
using namespace std;

int n;
int m[MAXN][MAXN];
int dp[MAXN][MAXN];
int d1[] = {1, -1, 0, 0};
int d2[] = {0, 0, 1, -1};

iii mp(int a, int b, int c) {return make_pair(a, make_pair(b, c));}

int main(){
	scanf("%d", &n);

	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			scanf("%d", &m[i][j]);
			dp[i][j] = INF;
		}
	}


	priority_queue <iii, vector <iii>, greater <iii> > pq;
	pq.push(mp(0, 0, 0));
	dp[0][0] = 0;

	while (!pq.empty()){
		iii atual = pq.top(); pq.pop();
		int x = atual.s.f; 
		int y = atual.s.s; 
		int custo = atual.f;

		if (custo > dp[x][y]) continue;

		for (int i=0; i<4; i++){
			int x1 = x+d1[i];
		 	int y1 = y+d2[i];

		 	if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < n){
		 		if (m[x1][y1] + dp[x][y] < dp[x1][y1]){
		 			dp[x1][y1] = m[x1][y1] + dp[x][y];
		 			pq.push(mp(dp[x1][y1], x1, y1));
		 		}
			}
		}
	}

	printf("%d\n", dp[n-1][n-1]);

	return 0;
}