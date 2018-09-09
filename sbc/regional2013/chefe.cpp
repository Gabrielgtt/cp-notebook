#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 510;

int n, m, q;

vector <int> pais[MAXN];
int idade[MAXN];
int mask[MAXN];
int aqui[MAXN];
bool vis[MAXN];

int res(int node){
	int ans = idade[aqui[node]];
	vis[node] = true;
	for (int i=0; i<pais[node].size(); i++){
		if (!vis[pais[node][i]])
			ans = min(ans, res(pais[node][i]));
	}
	return ans;
}

void gamb(int node){
	vis[node] = false;
	for (int i=0; i<pais[node].size(); i++){
		if (vis[pais[node][i]])
			gamb(pais[node][i]);
	}	
}

void solve(){
	for (int i=0; i<n; i++){
		scanf("%d", &idade[i]);
		mask[i] = i;
		aqui[i] = i;
		pais[i].clear();
	}
	int pai, filho;
	for (int i=0; i<m; i++){
		scanf("%d %d", &pai, &filho);
		pai--; filho--;
		pais[filho].emplace_back(pai);
	}
	int a ,b;
	char tipo;
	for (int i=0; i<q; i++){
		scanf(" %c", &tipo);
		if (tipo == 'T'){
			scanf("%d %d", &a, &b);
			a--; b--;

			swap(mask[a], mask[b]);
			aqui[mask[a]] = a;
			aqui[mask[b]] = b;

		} else if (tipo == 'P'){
			scanf("%d", &a);
			a--;
			int ans = 1e9;
			memset(vis, 0, sizeof vis);
			for (int i=0; i<pais[mask[a]].size(); i++){
				ans = min(ans, res(pais[mask[a]][i]));
			}

			if (ans == 1e9){
				printf("*\n");
			} else {
				printf("%d\n", ans);
			}

		}
	}
}


int main(){

	while (scanf("%d %d %d", &n, &m, &q) != EOF){
		solve();
	}

	return 0;
}