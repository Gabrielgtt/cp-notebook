#include <bits/stdc++.h>
#define MAXN 1000100
#define ll long long
#define ii pair <int, int>
#define f first
#define s second
#define pb push_back
using namespace std;

int bit[MAXN+2];

void update(int index){
	while (index <= MAXN){
		bit[index]++;
		index += index & (-index);
	}
}

int soma(int index){
	int res = 0;
	while (index > 0){
		res += bit[index];
		index -= index & (-index);
	}
	return res;
}

int main(){
	int n;
	scanf("%d", &n);

	int num;
	for (int i=0; i<n; i++){
		scanf("%d", &num);
		int gamb = MAXN - num;
		printf("%d\n", n - soma(gamb));
		update(gamb);
	}

	return 0;
}