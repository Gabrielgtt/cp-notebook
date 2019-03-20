#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx,tune=native")
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);

	map <string, string> pais;
	map <string, string> filhos;
	string pai, filho, lista[1010];
	int n, res = 0;
	cin >> n;
	while (n--){
		cin >> pai >> filho;

		if (filhos.find(pai) != filhos.end()){
			pais[filhos[pai]] = filho;
			filhos[filho] = filhos[pai];

		} else {
			lista[res++] = pai;
			pais[pai] = filho; 
			filhos[filho] = pai; 
		}
	}

	cout << res << endl;
	for (int i=0; i<res; i++){
		cout << lista[i] << " " << pais[lista[i]] << endl;
	}

	return 0;

}