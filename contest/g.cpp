#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define ii pair <int, int>
#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define INF 1e9
#define MOD 1000000007
#define debug(x) cerr << #x << " = " << x << endl
#define debug_arr(x, tam) cerr << #x << " = "; for (int i=0;i<tam;i++) printf("%d%c", x[i], " \n"[i == tam-1])
#define MAXN 200010
#define MAXSQRT 470
using namespace std;

ii bucket[MAXSQRT];
ii guardas[MAXN];
int raiz;
int n, q;
bool socorro;

ii junta(ii a, ii b){
	// printf("%d %d    %d %d\n", a.f, a.s, b.f, b.s);
	if (a == make_pair(1, 0) || b == make_pair(1, 0) ) return make_pair(1, 0);

	if (a.s < b.f || b.s < a.f){
		socorro = true;
		return make_pair(1, 0);
	}

	if (a.f <= b.f && b.s <= a.s){
		return b;
	}

	if (b.f <= a.f && a.s <= b.s){
		return a;
	}

	if (a.f <= b.f && a.s <= b.s){
		return make_pair(b.f, a.s);
	}

	if (b.f <= a.f && b.s <= a.s){
		return make_pair(a.f, b.s);
	}

	socorro = true;
	return make_pair(1, 0);
}

int query(int left, int right){

	socorro = false;

	ii inter = guardas[left];
	left++;

	while (left < right && left % raiz != 0){
		inter = junta(inter, guardas[left]);
		if (socorro) return 0;
		left++;
	}

	while (left + raiz - 1 <= right){
		inter = junta(inter, bucket[left/raiz]);
		if (socorro) return 0;
		left += raiz;
	}

	while (left <= right){
		inter = junta(inter, guardas[left]);
		if (socorro) return 0;
		left++;	
	}

	return inter.s - inter.f + 1;
}

void atualiza(int ind){
	int index = ind*raiz;
	bucket[ind] = make_pair(-1e9-1, 1e9+1);
	while (index < n && index/raiz == ind){
		bucket[ind] = junta(bucket[ind], guardas[index]);
		index++;
	}
}

int main(){
	scanf("%d %d", &n, &q);
	raiz = 450;

	for (int i=0; i<MAXSQRT; i++){
		bucket[i] = make_pair(-1e9-1, 1e9+1);
	}

	int l, r;
	for (int i=0; i<n; i++){
		scanf("%d %d", &l, &r);
		guardas[i].f = l;
		guardas[i].s = r;
		bucket[i/raiz] = junta(bucket[i/raiz], guardas[i]);
	}

	char tipo;
	int gua;
	for (int i=0; i<q; i++){
		scanf(" %c", &tipo);

		if (tipo == '?'){
			scanf("%d %d", &l, &r);
			l--; r--;
			printf("%d\n", query(l, r));

		} else if (tipo == 'C'){
			scanf("%d %d %d", &gua, &l, &r);
			gua--;
			guardas[gua].f = l;
			guardas[gua].s = r;
			atualiza(gua/raiz);
		}
	}

	return 0;
}