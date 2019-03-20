#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, arr[104];
	scanf("%d", &n);

	int num1 = 0, p1 = -1, p2, aux=1;
	long long int res = 1;

	for (int i=0; i<n; i++){
		scanf("%d", &arr[i]);
		if (p1 == -1){
			if (arr[i]){
				p1 = i;
			}
		} else {
			if (arr[i]){
				p2 = i;
			}
		}
		num1 += arr[i];
	}

	if (num1 == 1) printf("1\n");
	else if (num1 == 0) printf("0\n");
	else {
		aux = 1;
		for (int i=p1; i<=p2; i++){
			if (arr[i] == 1){
				res *= aux;
				aux = 1;
			} else {
				aux++;
			}
		}
		cout << res << endl;
	}
	return 0;
}