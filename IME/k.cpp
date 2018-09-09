#include <bits/stdc++.h>
#define MAXN 200010
#define MOD 1000000007
#define f first
#define s second
#define ll long long
#define ii pair <int, int>
#define mp make_pair
#define iiii pair <ii, ii>
using namespace std;

vector <ii> grafo[MAXN];
ii galera[4];
int dist[MAXN][4];
int n, m;

iiii con(int a, int b, int c, int d){
	return mp(mp(a, b), mp(c, d)); 
}

int gamb(int mod, int atual){
	if (atual < mod) atual+=3;
	return atual - mod;
}

int solve(int modulo){
	for (int i=0; i<=n; i++) for (int j=0; j<3; j++) dist[i][j] = 1e9;

	priority_queue <iiii, vector <iiii>, greater <iiii> > pq;
	pq.push(con(0, 1, 0, 1e9)); // dist, node, numArestas, menorAresta
	dist[1][0] = 0;

	while(!pq.empty()){
		iiii front = pq.top();
		int atual = front.f.s;
		int distAtual = front.f.f;
		int mod = front.s.f;
		pq.pop();

		if (distAtual > dist[atual][mod]) continue;

		for (int i=0; i<grafo[atual].size(); i++){
			ii prox = grafo[atual][i];
			int vert = prox.s;
			int aresta = prox.f;


			if (dist[atual][mod] + aresta < dist[vert][(mod+1)%3]){

				dist[vert][(mod+1)%3] = dist[atual][mod] + aresta;
				if (vert != n) pq.push(con(dist[vert][(mod+1)%3], vert, (mod+1) % 3, 2));

			}
		}		
	}
	
	return dist[n][modulo];
}

int main(){
	scanf("%d %d", &n, &m);

	if (m == 1){
		printf("Gon\n");
		printf("Killua\n");
		printf("me\n");
		return 0;
	}

	int de, para, custo;
	for (int i=0; i<m; i++){
		scanf("%d %d %d", &de, &para, &custo);
		grafo[de].push_back(ii(custo, para));
		grafo[para].push_back(ii(custo, de));
	}

	for (int i=0; i<3; i++){
		galera[i].first = solve(i);
		// printf("%d\n", galera[i].first);
		galera[i].second = i;
	}

	sort(galera, galera+3);

	for(int i=0; i<3; i++){
		if (galera[i].second == 0) printf("me\n");
		if (galera[i].second == 1) printf("Gon\n");
		if (galera[i].second == 2) printf("Killua\n");
	}

	return 0;
}