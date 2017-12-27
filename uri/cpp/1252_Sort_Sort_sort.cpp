#include <bits/stdc++.h>

using namespace std;

int n, m;

bool ss(int a, int b){
	if (a%m == b%m){

		if ((a & 1) && (b & 1)){
			return  a > b;
		} 
		
		if (!(a & 1) && !(b & 1)) {
			return a < b;
		} 
		return (a & 1);
	}

	return a%m < b%m;
}


int main(){

	while (1){
		scanf("%d %d", &n, &m);
		printf("%d %d\n", n, m);

		if (n == 0 && m == 0) break;


		int array[n];
		for (int i=0; i<n; i++){
			scanf("%d", &array[i]);
		}


		sort(array, array+n, ss);

		for (int i=0; i<n; i++){
			printf("%d\n", array[i]);
		}

	}

	return 0;
}