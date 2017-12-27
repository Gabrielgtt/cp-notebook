#include <bits/stdc++.h>
using namespace std;

map <string, vector<string> > grafo;
int n, g;
vector<string> ans;

void bfs(){
	queue <pair <string, int> > fila;
	map<string, bool> flag;
	flag["Rerisson"] = true;

	for (int i=0; i<grafo["Rerisson"].size(); i++){
		fila.push(make_pair(grafo["Rerisson"][i], 1));
	}

	while (!fila.empty()){
		pair <string, int> atual = fila.front();
		fila.pop();
		flag[atual.first] = true;

		if (atual.second <= g) ans.push_back(atual.first);

		for (int i=0; i<grafo[atual.first].size(); i++){
			if (flag[grafo[atual.first][i]] == false){
				flag[grafo[atual.first][i]] = true;
				fila.push(make_pair(grafo[atual.first][i], atual.second+1));
			}
		}
	}
}

int main(){
	cin >> n >> g;
	string nome1, nome2;

	for (int i=0; i<n; i++){
		cin >> nome1 >> nome2;
		grafo[nome1].push_back(nome2);
		grafo[nome2].push_back(nome1);
	}

	bfs();

	sort(ans.begin(), ans.end());

	cout << ans.size() << endl;
	for (int i=0; i<ans.size(); i++){
		cout << ans[i] << endl;
	}

	return 0;
}