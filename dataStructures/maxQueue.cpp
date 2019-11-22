#include <bits/stdc++.h>
#define ii pair <int, int>
using namespace std;

int n;
// ------------------------------------------------------------------------------
void maxQueue(int tam, int arr[]) {
	deque <ii> q;
	for (int i=0; i<n; i++) {
		while(!q.empty() && i - q.front().second >= tam) q.pop_front();
		while(!q.empty() && q.back().first < arr[i]) q.pop_back();
		q.emplace_back(arr[i], i);
		printf("%d\n", q.front().first);
	}
}
// ------------------------------------------------------------------------------ 8955867935

int main() {
	int arr[10] = {1, -1, 2, -4, 3, 5, 10, 3, -3, 5};
	n = 10;
	maxQueue(3, arr);
	return 0;
}
