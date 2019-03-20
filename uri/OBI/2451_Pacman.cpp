#include <bits/stdc++.h>
#define MAXN 200
using namespace std;

int main(){
	int n;
	cin >> n;		
	char matriz[MAXN][MAXN];
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cin >> matriz[i][j];
		}
	}

	int res = 0, atual = 0;
	for (int i=0; i<n; i++){
		if (i & 1){
			for (int j=n-1; j>=0; j--){
				if (matriz[i][j] == 'o') res = max(++atual, res);
				else if (matriz[i][j] == 'A') atual = 0;
			}
		} else {
			for (int j=0; j<n; j++){
				if (matriz[i][j] == 'o') res = max(++atual, res);
				else if (matriz[i][j] == 'A') atual = 0;
			}
		}
	}

	printf("%d\n", res);

	return 0;
}