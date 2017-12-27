#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;

int main(){
	int a, b, c;
	int linha[MAXN], flag[MAXN], num;

	while (scanf("%d %d %d", &a, &b, &c) and a != 0){
		int res;
		memset(linha, 0, sizeof linha);
		memset(flag, 0, sizeof flag);

		for (int lin=0; lin<b; lin++){
			for (int col=0; col<a; col++){
				scanf("%d", &num);
				linha[col] += num;
				if (linha[col] >= c) res++;

			}
		}
	}

	return 0;
}