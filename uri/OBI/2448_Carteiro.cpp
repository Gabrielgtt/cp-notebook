#include <bits/stdc++.h>
#define MAXN 50000
using namespace std;

int main(){
	int n, m, aux;
	scanf("%d %d", &n, &m);
	map <int, int> indexes;

	for (int i=0; i<n; i++){
		scanf("%d", &aux);
		indexes[aux] = i;
	}

	int atual = 0, res = 0;
	for (int i=0; i<m; i++){
		scanf("%d", &aux);
		res += abs(atual - indexes[aux]);
		atual = indexes[aux];
	}

	printf("%d\n", res);
	return 0;
}