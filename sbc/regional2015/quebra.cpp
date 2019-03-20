#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

const int MAXN = 111;
typedef long long ll;
typedef pair <string, ll> si;

ll somaL[MAXN];
ll somaC[MAXN];

map <string, ll> rows[MAXN];
map <string, ll> cols[MAXN];
ll somaTotal = 0;
int n, m;

void limpa(string var, ll valor){
	map <string, ll>::iterator it;
	for (int i=0; i<n; i++){
		if (rows[i].count(var)){
			it = rows[i].find(var);
			si aux = *it;
			somaTotal -= aux.s * valor;
			somaL[i] -= aux.s * valor;
			rows[i].erase(it);
		}
	}
	for (int i=0; i<m; i++){
		if (cols[i].count(var)){
			it = cols[i].find(var);
			si aux = *it;
			somaTotal -= aux.s * valor;
			somaC[i] -= aux.s * valor;
			cols[i].erase(it);
		}
	}
}

int main(){
	cin >> n >> m;

	string var;
	set <string> difs;
	for (int i=0; i<n; i++){ 
		for (int j=0; j<=m; j++){
			if (j == m){
				cin >> somaL[i];
				somaTotal += somaL[i];
			} else {
				cin >> var;
				difs.insert(var);
				rows[i][var] += 1;
				cols[j][var] += 1;
			}
		}
	}

	for (int i=0; i<m; i++){
		cin >> somaC[i];
		somaTotal += somaC[i];
	}	

	vector < si > ans;
	while (!difs.empty()){		
		for (int i=0; i<n; i++){
			if (rows[i].size() == 1){
				si atual = *rows[i].begin();
				ans.emplace_back(si(atual.f, somaL[i] / atual.s));
				difs.erase(atual.f);
				limpa(atual.f, somaL[i] / atual.s);
			}
		}

		for (int i=0; i<m; i++){
			if (cols[i].size() == 1){
				si atual = *cols[i].begin();
				ans.emplace_back(si(atual.f, somaC[i] / atual.s));
				difs.erase(atual.f);
				limpa(atual.f, somaC[i] / atual.s);
			}
		}
	}

	sort(ans.begin(), ans.end());

	for (si res : ans){
		cout << res.f << " " << res.s << endl;
	}


	return 0;
}