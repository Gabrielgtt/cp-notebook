#include <bits/stdc++.h>
using namespace std;

int main(){

	int n, m, contador=1, arr[10010], num;
	
	while (scanf("%d %d", &n, &m) && n != 0){
		printf("CASE# %d:\n", contador++);
		map<int, int> mapa;
		

		for (int i = 0; i < n; i++){
			scanf("%d", &arr[i]);
		}

		sort(arr, arr+n);
		
		for (int i = 0; i < n; i++){
			if (mapa.find(arr[i]) == mapa.end()){
				mapa[arr[i]] = i;
			}
		}

		for (int i = 0; i < m; i++){
			scanf("%d", &num);

			if (mapa.find(num) != mapa.end()){
				printf("%d found at %d\n", num, mapa[num]+1);
			} else {
				printf("%d not found\n", num);
			}	
		}
	}
}