#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define ii pair <int, int> 
#define iii pair <int, ii> 
#define MAXN 12
using namespace std;


int main(){
	int n;
	scanf("%d", &n);

	int res = 0;
	while(n > 0){
		res++;
		n /= 2;
	}

	printf("%d\n", res);
	return 0;
}