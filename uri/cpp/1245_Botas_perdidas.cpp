#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while (scanf("%d", &n) != EOF){
		int x, res=0, Ds[100], Es[100];
		memset(Ds, 0, sizeof Ds);
		memset(Es, 0, sizeof Es);
		char a;
		
		for (int i=0; i<n; i++){
			scanf("%d %c", &x, &a);
			int ant = min(Ds[x], Es[x]);
			if (a == 'D') Ds[x]++;
			if (a == 'E') Es[x]++;
			res += min(Ds[x], Es[x]) - ant;
		}

		printf("%d\n", res);
	}
	return 0;
}