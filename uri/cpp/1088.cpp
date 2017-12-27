#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx,tune=native")
#define MAXN 100010
using namespace std;

int arr[MAXN], temp[MAXN];
int n;
long long int inver;

void merge(int start, int mid, int end){
	if (end >= n) end = n-1;

	int i = start;
	int k = start;
	int j = mid+1;

	while (i <= mid && j <= end){

		if (arr[i] <= arr[j]){
			temp[k++] = arr[i++];
		} else {
			temp[k++] = arr[j++];
			inver += mid - i + 1;
		}
	}

	while (i <= mid) temp[k++] = arr[i++];
	while (j <= end) temp[k++] = arr[j++];

	for (int e = start; e <= end; e++) arr[e] = temp[e];
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

	while (scanf("%d", &n) && n != 0){
		inver = 0;
		
		for (int i=0; i<n; i++){
			scanf("%d", &arr[i]);
		}

		mergesort(0, n);

		if (inver & 1) printf("Marcelo\n");
		else printf("Carlos\n");
	}



	return 0;
}
