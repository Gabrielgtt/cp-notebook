#include <bits/stdc++.h>
#define ii pair <int, int>
using namespace std;

int main(){
	string pal;
	int ctrl=0;
	while (getline(cin, pal)){
		if
		set <ii> mapa;
		int cont[300];
		memset(cont, 0, sizeof cont);

		for (int i=0; i<pal.size(); i++){
			cont[pal[i]]++;
		}

		for (int i=0; i<pal.size(); i++){
			if (cont[pal[i]] != 0){
				mapa.insert(make_pair(cont[pal[i]], pal[i]));
				cont[pal[i]] = 0;
			}
		}

		for (set <ii>::iterator it = mapa.begin(); it != mapa.end(); it++){
			ii par = *it;
			cout <<  par.second << " " << par.first << endl;
		}
	}
	return 0;
}