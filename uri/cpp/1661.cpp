#include <bits/stdc++.h>
using namespace std;

long long int arr[100010];

int main(){
	int n;

	while (cin >> n){
		if (n==0) break;

		for (int i=0; i<n; i++){
			cin >> arr[i];
		}

		for (int i=1; i<n; i++){
			arr[i] += arr[i-1];
		}

		long long int res = arr[0] < 0 ? -arr[0] : arr[0];
		for (int i=1; i<n; i++){
			res += arr[i] < 0 ? -arr[i] : arr[i];
		}

		res += arr[n-1];

		cout << res << endl;

	}

	return 0;
}