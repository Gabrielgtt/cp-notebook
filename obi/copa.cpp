#include <bits/stdc++.h>
#define ll long long
#define MAXN 10000
using namespace std;

ll res = 0;
int parent[MAXN], r[MAXN];

struct edge{
	int de, para, custo, tipo;
} e[MAXN];

int find(int a){
	return parent[a] == 0 ? a : find(parent[a]);
}

void uni(edge a){
	int paia = find(a.de);
	int paib = find(a.para);

	if (paia != paib){
		res += a.custo;

		if (r[paia] > r[paib]){
			parent[paib] = paia;
		} else {
			parent[paia] = paib;
			if (r[paia] == r[paib]) r[paib]++;
		}
	}
}

bool comp(edge a, edge b){
	if (a.tipo != b.tipo) return a.tipo < b.tipo;
	return a.custo < b.custo;
}

int main(){
	int n, f, r;
	scanf("%d %d %d", &n, &f, &r);

	int de ,para, custo;
	for (int i=0; i<f; i++){
		scanf("%d %d %d", &de, &para, &custo);
		e[i].de = de;
		e[i].para = para;
		e[i].custo = custo;
		e[i].tipo = 0;
	}

	for (int i=f; i<f+r; i++){
		scanf("%d %d %d", &de, &para, &custo);
		e[i].de = de;
		e[i].para = para;
		e[i].custo = custo;
		e[i].tipo = 1;
	}

	sort(e, e + (f+r), comp);

	for (int i=0; i<f+r; i++){
		uni(e[i]);
	}

	printf("%lld\n", res);

	return 0;
}