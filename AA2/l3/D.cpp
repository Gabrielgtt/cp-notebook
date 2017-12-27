#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int BIT[MAXN], n, arr[MAXN];

void update(int index, int num){
	while (index <= n){
		BIT[index] += num;
		index += index & (-index);
	}
}

int getSum(int index){
	int sum = 0;

	while (index > 0){
		sum += BIT[index];
		index -= index & (-index);
	}

	return sum;
}

int main(){
	scanf("%d", &n);

	for (int i = 1; i <= n; i++){
		scanf("%d", &arr[i]);

		update(i, arr[i]);
		// printf("%d\n", getSum(i));
	}

	char tipo;
	int pos;
	while (cin >> tipo >> pos){

		if (tipo == 'a'){
			update(pos, -arr[pos]);
		} else {
			printf("%d\n", getSum(pos-1));
		}
	}

	return 0;
}