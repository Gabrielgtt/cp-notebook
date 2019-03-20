#include <bits/stdc++.h>
#define MAXN 500010
#define ii pair <long long, int>
using namespace std;

bool vis[MAXN];
long long res[MAXN];
vector<ii> grafo[MAXN];

long long dfs(int atual){
	vis[atual] = true;
	for (int i=0; i<grafo[atual].size(); i++){
		ii prox = grafo[atual][i];

		res[atual] = min(res[atual], prox.first + res[prox.second]);
		res[prox.second] = min(res[prox.second], prox.first + res[atual]);
		if (!vis[prox.second]){
			res[atual] = min(res[atual], prox.first + dfs(prox.second));
			res[prox.second] = min(res[prox.second], prox.first + res[atual]);
		} 
	}

	return res[atual];
}

int main(){
	int m, n;
	scanf("%d %d", &n, &m);
	int de, para;
	long long c;
	for (int i=0; i<m; i++){
		scanf("%d %d %lld", &de, &para, &c);
		grafo[de].push_back(make_pair(c*2ll, para));
		grafo[para].push_back(make_pair(c*2ll, de));
	}

	for (int i=1; i<=n; i++){
		scanf("%lld", &res[i]);
	}

	for (int i=1; i<=n; i++){
		dfs(i);
	}

	for (int i=1; i<=n; i++){
		if (i > 1) cout << " ";
		cout << res[i];
	}
	cout << endl;

	return 0;
}