#include <bits/stdc++.h>
#define MAXN 200010
#define ll long long
#define ii pair <int, int>
#define f first
#define s second
#define pb push_back
using namespace std;

vector <int> grafo[MAXN];
ii arestas[MAXN];
int qs[MAXN];
int res[MAXN];
int pai[MAXN];
int r[MAXN];

int find(int a){
	return pai[a] == a ? a : pai[a] = find(pai[a]);
}

bool uniao(int a, int b){
	int paia = find(a);
	int paib = find(b);

	if (paia == paib){
		return false;
	} else {
		if (r[paia] > r[paib]){
			pai[paib] = paia;
		} else {
			pai[paia] = paib;
			if (r[paia] == r[paib]) r[paib]++;
		}
		return true;
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i=0; i<=n; i++) pai[i] = i;

	int de, para;
	for (int i=0; i<m; i++){
		scanf("%d %d", &de, &para);
		arestas[i+1].first = de;
		arestas[i+1].second = para;
	}


	for (int i=0; i<m; i++){
		scanf("%d", &qs[i]);
	}

	int ans = n;
	for (int i=m-1; i>=0; i--){
		res[i] = ans;

		if (uniao(arestas[qs[i]].f, arestas[qs[i]].s)){
			ans--;
		}
	}

	for (int i=0; i<m; i++){
		printf("%d\n", res[i]);
	}

	return 0;
}