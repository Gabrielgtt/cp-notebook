#include <bits/stdc++.h>

using namespace std;

int main (){
	int a, b, c, d, e, array[53];

	while (1){
		memset(array, 0, sizeof array);
		scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
		if (a == 0) break;
		
		array[a] = 1;
		array[b] = 1;
		array[c] = 1;
		array[d] = 2;
		array[e] = 2;

		int maior = max(max(a, b), c);

		int aux=0;
		vector<int> vec;
		for (int i=0; i<53; i++){
			if (array[i] == 1) aux++;
			else if (array[i] == 2) vec.push_back(aux);
		}

		int mode=-1;

		// printf("A menor carta eh maior que %d, a outra eh maior que %d\n", vec[0], vec[1]);

		if (vec[0] + vec[1] == 3){

			if (!vec[0] || !vec[1]){
				mode = 3;
			}

		} else if (vec[0] + vec[1] == 4){

			if (vec[0] == 2) mode = 2;
			else mode = 3;

		} else if (vec[0] + vec[1] == 5) mode = 2;
		else if (vec[0] + vec[1] == 6) mode = 0;

		if (mode == -1) {
			printf("-1\n");
		} else {

			int flag = 1;
			for (int i=1; i<=52; i++){
				if (mode == 0 && array[i] == 0){
					flag = 0;
					printf("%d\n", i);
					break;
				}

				if (array[i] == 1 && mode > 0) mode--;
			}

			if (flag) printf("-1\n");
		}


	}

	return 0;
}