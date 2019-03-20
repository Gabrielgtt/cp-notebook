#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

typedef long long ll;
typedef pair <ll, pair <int, int> > iii;
typedef pair <ll, int> ii;

const ll INF = 1e17;
const int MAXN = 50010;

vector <ii> grafo[MAXN];
ll dist[MAXN][2];

iii make(ll a, int b, int c){
	return make_pair(a, ii(b, c));
}

int c, v, de, para;
ll custo;

ll solve(){
	priority_queue <iii, vector <iii>, greater <iii> > pq;
	pq.push(make(0, 1, 0));
	dist[1][0] = 0;	

	while (!pq.empty()){
		iii aux = pq.top();
		pq.pop();
		int atual = aux.s.f;
		ll distAtual = aux.f;
		int par = aux.s.s;

		if (dist[atual][par] < distAtual) continue;
			par ^= 1;

		for (ii prox : grafo[atual]){
			if (dist[atual][par^1] + prox.f < dist[prox.s][par]){
				dist[prox.s][par] = dist[atual][par^1] + prox.f;
				pq.push(make(dist[prox.s][par], prox.s, par));
			}
		}
	}

	return dist[c][0];
}

int main(){
	scanf("%d %d", &c, &v);

	for (int i=1; i<=c; i++){
		for (int j=0; j<2; j++){
			dist[i][j] = INF;
		}
	}

	for (int i=0; i<v; i++){
		scanf("%d %d %lld", &de, &para, &custo);
		grafo[de].push_back(ii(custo, para));
		grafo[para].push_back(ii(custo, de));
	}

	ll res = solve();
	printf("%lld\n", res == 1e17 ? -1 : res);
	return 0;
}