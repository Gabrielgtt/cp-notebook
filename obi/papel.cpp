#include <bits/stdc++.h>
#define MAXN 200000
#define ii pair <int, int>
using namespace std;

bool vis[MAXN];

int main(){		
	int n;
	scanf("%d", &n);
	vector < pair <int, int> > inter;

	int num;
	for (int i=1; i<=n; i++){
		scanf("%d", &num);
		inter.push_back(make_pair(num, i));
	}

	int res = 0;

	sort(inter.rbegin(), inter.rend());

	int aux = 1;
	for (pair <int, int> atual : inter){
		int index = atual.second;
		int h = atual.first;

		vis[index] = true;
		if (!vis[index+1] && !vis[index-1]){
			aux++;
		} else if (vis[index+1] && vis[index-1]){
			aux--;
		}

		res = max(aux, res);
	}

	printf("%d\n", res);

	return 0;
}