#include <bits/stdc++.h>

using namespace std;

int main(){
	int h, l;

	while (scanf("%d %d", &h, &l) && l != 0 && h != 0){

		int last = h, atual, res=0;
		for (int i=0; i<l; i++){
			scanf("%d", &atual);
			if (last > atual) res += last - atual;
			last = atual; 
		}

		printf("%d\n", res);
	}

	return 0;
}