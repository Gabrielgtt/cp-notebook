#include <bits/stdc++.h>
using namespace std;

int main(){
	int arr[10], arr2[10];
	for (int i=0; i<6; i++){
		cin >> arr[i];		
	}
	for (int i=0; i<6; i++){
		cin >> arr2[i];
	}
	int res = 0;
	for (int i=0; i<6; i++){
		for (int j=0; j<6; j++){
			if (arr[i] == arr2[j]){
				res++;
				break;
			}
		}
	}
	if (res < 3){
		printf("azar\n");
	} else if (res == 3){
		printf("terno\n");
	} else if (res == 4){
		printf("quadra\n");
	} else if (res == 5){
		printf("quina\n");
	} else if (res == 6){
		printf("sena\n");		
	}

	return 0;
}