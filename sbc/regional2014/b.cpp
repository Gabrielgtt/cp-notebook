#include <bits/stdc++.h>
using namespace std;

int log(int n) { return (n == 1 || n == 0) ? 0 : log(n/2) + 1;}

int main(){
	int n;
	int arr[200010];
	scanf("%d", &n);
	if (n == pow(2, log(n))) printf("%d\n", log(n) * 2);
	else {
		int f = n/2, s = 0, i = 0;
		while (f < n){
			arr[f] = i++;
			arr[s] = i++;
			f++;
			s++;
		}
		int pos = 1, res = 1;
		while (pos != 0){
			pos = arr[pos];
			res++;
		}
		printf("%d\n", res);
	}
	return 0;
}