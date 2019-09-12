#include <bits/stdc++.h>
#define ii pair <int, int>
using namespace std;

int n;
// ------------------------------------------------------------------------------
void maxQueue(int tam, int arr[]) {
	deque <ii> que;
	for (int i=0; i<n; i++) {
		while(!que.empty() && i - que.front().second >= tam) que.pop_front();
		while(!que.empty() && que.back().first < arr[i]) que.pop_back();
		que.emplace_back(arr[i], i);
		printf("%d\n", que.front().first);
	}
}
// ------------------------------------------------------------------------------ 8955867935

int main() {
	int arr[10] = {1, -1, 2, -4, 3, 5, 10, 3, -3, 5};
	n = 10;
	maxQueue(3, arr);
	return 0;
}
