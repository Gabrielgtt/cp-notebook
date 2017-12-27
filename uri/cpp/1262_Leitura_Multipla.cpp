#include <bits/stdc++.h>
using namespace std;

int main(){
	string pal;
	int n, res, aux;

	while (cin >> pal){
		res = 0;
		cin >> n;
		aux = n;

		for (int i=0; i<pal.size(); i++){
			if (pal[i] == 'W') res++, aux = n;
			else if (aux == n) res++, aux--;
			else aux--;

			if (aux == 0) aux = n;
		}

		printf("%d\n", res);
	}

	return 0;
}