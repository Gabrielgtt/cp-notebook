#include <bits/stdc++.h>
#define MAXN 200010 
using namespace std;

int arr[MAXN*4], temp[MAXN];
long long int inver = 0;
int n;

void merge(int start, int mid, int end){
	if (end >= n) end = n-1;

	int i = start;
	int k = start;
	int j = mid+1;

	while (i <= mid && j <= end){
		if (arr[i] <= arr[j]){
			temp[k] = arr[i];
			k++; i++;

		} else {
			temp[k] = arr[j];
			k++; j++;
			inver += mid-i+1;
		}
	}

	while (i <= mid) temp[k++] = arr[i++];
	while (j <= end) temp[k++] = arr[j++];

	for (int e = start; e <= end; e++){
		arr[e] = temp[e];
	}


}

void mergesort(int start, int end){
	if (start == end) {
		temp[start] = arr[start];
	} else {

		int mid = (start+end)/2;

		mergesort (start, mid);
		mergesort (mid+1, end);

		merge(start, mid, end);
	}
}


int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		scanf("%d", &n);

		for (int i=0; i<n; i++){
			scanf("%d", &arr[i]);
		}

		mergesort(0, n);

		cout << inver << endl;
		inver = 0;
	}

	return 0;
}