#include <bits/stdc++.h>
#define MAXN 1000000
using namespace std;

int n, bit[MAXN], arr[MAXN];
void update(int index, int value){
	while (index <= n){
		bit[index] += value;
		index += index & (-index);
	}	
}

int soma(int index){
	int s = 0;
	while (index > 0){
		s += bit[index];
		index -= index & (-index);
	}
	return s;
}

int main(){
	int q;
	scanf("%d %d", &n, &q);

	for (int i=1; i<=n; i++){
		scanf("%d", &arr[i]);
		update(i, arr[i]);
	}

	int tipo, index, value;
	while (q--){
		scanf("%d", &tipo);
		if (tipo == 1){
			scanf("%d", &index);
			printf("%d\n", soma(index));
		} else if (tipo == 0){
			scanf("%d %d", &index, &value);
			update(index, value - arr[index]);
			arr[index] = value;
		}
	}

	return 0;
}