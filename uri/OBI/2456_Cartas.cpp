#include <bits/stdc++.h>
using namespace std;

int main(){
	int arr[7];
	int ord = 0;
	bool flag = false;
	for (int i=0; i<5; i++){
		scanf("%d", &arr[i]);
		if (i > 0){
			if (arr[i] > arr[i-1]){
				ord++;
			}
		}
	}

	if (ord == 4) {
		printf("C\n");
	} else {
		ord = 0;
		for (int i=1; i<5; i++){
			if (arr[i] < arr[i-1]) ord++;
		}
		if (ord == 4) {
			printf("D\n");
		} else {
			printf("N\n");
		}
	}

	return 0;
}