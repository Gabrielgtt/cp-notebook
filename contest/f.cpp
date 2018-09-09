#include <bits/stdc++.h>
#define MAXN 100100
#define ll long long
#define debug_arr(arr, n) cout << #arr << " = "; for (int i=0; i<n; i++) cout << arr[i] << " \n"[i == n-1]
using namespace std;

set <ll> precisa[MAXN];
	
int main(){
	int n;
	scanf("%d", &n);

	set <ll> temp;
	set <ll> odeia;

	int tipo, qtd;
	ll num;

	bool g1 = true;

	int ind = 0;
	for (int i=0; i<n; i++){
		scanf("%d %d", &tipo, &qtd);

		if (tipo == 1){
			for (int j=0; j<qtd; j++){
				scanf("%lld", &num);

				if (g1)	precisa[ind].insert(num);
				else {
					if (precisa[ind].count(num)){
						precisa[ind+1].insert(num);
					}
				}
			}

			if (!g1) ind++;
			g1 = false;			

		} else {
			for (int j=0; j<qtd; j++){
				scanf("%lld", &num);
				odeia.insert(num);
			}
		}
	}

	for (auto numero : odeia){
		if (precisa[ind].count(numero)){
			precisa[ind].erase(numero);
		}
	}	


	if (g1) printf("%lld\n", 1000000000000000000 - (ll) odeia.size());
	else printf("%d\n", (int) precisa[ind].size());

	return 0;
}