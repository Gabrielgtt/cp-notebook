#include <bits/stdc++.h>

using namespace std;

int main(){
	while (1){
		int n, picos = 1, crescendo=0, freqs[2], nova, truque=0;

		scanf("%d", &n);
		if (n == 0) break;

		if (n == 1) {
			scanf("%d", &freqs[0]);
			printf("1\n");

		} else if (n == 2) {
			scanf("%d %d", &freqs[0], &freqs[1]);
			printf("2\n");

		} else {
			scanf("%d", &freqs[0]);
			scanf("%d", &freqs[1]);

			if (freqs[0] < freqs[1]) crescendo = 1;

			truque = crescendo;

			for (int i=2; i<n; i++){
				scanf("%d", &nova);


				if (crescendo){

					if (nova < freqs[1]){
						// printf(">>%d-%d\n", freqs[1], nova);
						crescendo = 0;
						picos++;
					}

				} else {

					if (nova > freqs[1]){
						// printf(">>%d-%d\n", freqs[1], nova);
						crescendo = 1;
						picos++;
					}

				}

				freqs[1] = nova;
			}
			
			if (crescendo == truque) picos++;

			printf("%d\n", picos);

		}
	}
	
	return 0;
}