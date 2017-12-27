#include <bits/stdc++.h>

using namespace std;

void solve(int n){
	double media = 0, a, res=0;
	double array[n+1];

	for (int i=0; i<n; i++){
		scanf("%lf", &a);
		array[i] = a;
		media += a;
	}	

	// printf("%lf\n", media);
	media /= n;
	double aux;

	for (int i=0; i<n; i++){
		if (array[i] > media){
			// printf("%lf\n", array[i]-media);
			aux = array[i]-media;
			// aux = floor(aux*100)/100;
			res += aux;
			// printf("%lf\n", res);
		}
	}

	printf("$%.2lf\n", res);
}	

int main(){
	int n;
	while (scanf("%d", &n) && n != 0){
		solve(n);
	}
	return 0;
}