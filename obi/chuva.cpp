#include <bits/stdc++.h>
#define MAXN 200000
using namespace std;

int arr[MAXN];
int cont[MAXN];

int main(){
	int n;
	scanf("%d", &n);

	for (int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}

	priority_queue <int, vector <int>> pq;

	for (int i=0; i<n; i++){
		pq.push(arr[i]);
		if (pq.top() != arr[i]){
			cont[i]++;
		}
	}

	while (!pq.empty()) pq.pop();

	int res = 0;
	for (int i=n-1; i>=0; i--){
		pq.push(arr[i]);
		if (pq.top() != arr[i]){
			if (cont[i]) res++;
		}
	}

	printf("%d\n", res);
	return 0;
}