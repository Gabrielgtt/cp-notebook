#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;

	pair <int, int> arr[100010];
	while (cin >> n){

		for (int i=0; i<n; i++){
			cin >> arr[i].first >> arr[i].second;
		}

		sort(arr, arr+n);

		int atual = 1;
		for (int i=0; i<n; i++){
			if (arr[i].first <= atual){
				atual += arr[i].second;
			} else {
				atual = arr[i].first + arr[i].second;
			}
		}

		printf("%d\n", atual);

	}
}