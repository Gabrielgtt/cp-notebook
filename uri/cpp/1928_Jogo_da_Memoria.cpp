#include <bits/stdc++.h>
#define MAXN 100001
using namespace std;

int bfs(vector<int> grafo[], int cor[], int start){
	int vis[MAXN], dist[MAXN], v;
	memset(vis, 0, sizeof vis);
	queue <int> fila;	
	fila.push(start);
	vis[start] = 1;
	dist[start] = 0;

	while (!fila.empty()){
		v = fila.front(); fila.pop();
		
		if (cor[v] == cor[start] and v != start) return dist[v];

		for (int i=0; i<grafo[v].size(); i++){
			if (!vis[grafo[v][i]]) {
				vis[grafo[v][i]] = 1;
				dist[grafo[v][i]] = dist[v] + 1;
				fila.push(grafo[v][i]);
			}
		}

	}	

}

int main(){
	int n;
	scanf("%d", &n);

	int cor[n+1];
	for (int i=1; i<=n; i++){
		scanf("%d", &cor[i]);
	}

	vector <int> grafo[n+1];
	int a, b;
	for (int i=0; i<n-1; i++){
		scanf("%d %d", &a, &b);
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}

	int flags[n/2+2], res=0;
	memset(flags, 0, sizeof flags);

	for (int i=1; i<=n; i++){
		if (flags[cor[i]] == 0){
			flags[cor[i]] = 1;
			res += bfs(grafo, cor, i);
		}
	}

	printf("%d\n", res);
}