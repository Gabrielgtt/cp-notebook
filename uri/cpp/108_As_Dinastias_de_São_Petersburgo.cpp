#include <bits/stdc++.h>
#define eb emplace_back
#define MAXN 1010
using namespace std;

int match[MAXN], vis[MAXN];
vector <int> grafo[MAXN];
		
int bpm(int node){
	if (vis[node]) return 0;
	vis[node] = 1;
	for (int i=0; i<grafo[node].size(); i++){
		if (match[grafo[node][i]] == -1 || bpm(match[grafo[node][i]])){
			match[grafo[node][i]] = node;
			return 1;
		}
	}
	return 0;
}

int main(){
	int numImps, numRelacoes, pai, filho;
	while (scanf("%d %d", &numImps, &numRelacoes) != EOF){
		for (int i=1; i<=numImps; i++) grafo[i].clear(), match[i] = -1;
		for (int i=0; i<numRelacoes; i++){
			scanf("%d %d", &pai, &filho);
			grafo[pai].eb(filho);
			grafo[filho].eb(pai);
		}
		int res = 0;
		for (int i=1; i<=numImps; i++){
			memset(vis, 0, sizeof vis);
			res += bpm(i);
		}
		printf("%d\n", res);
	}
	return 0;
}