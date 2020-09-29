#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------------------------
typedef pair <int, int> pii;

// O(n) - Max element in arr[i-tam+1..i] for each i
vector <int> maxQueue(int tam, int arr[], int n) {
	deque <pii> q;
	vector <int> res;
	for (int i=0; i<n; i++) {
		while(!q.empty() && i - q.front().second >= tam) q.pop_front();
		while(!q.empty() && q.back().first < arr[i]) q.pop_back();
		q.emplace_back(arr[i], i);
		res.emplace_back(q.front().first);
	}
	return res;
}
// ------------------------------------------------------------------------------ 8955867935

int main() {
	int arr[10] = {10, -1, 2, -4, 3, 5, 10, 3, -3, 5};
	assert(maxQueue(3, arr, 10) == vector<int>({10, 10, 10, 2, 3, 5, 10, 10, 10, 5}));
	return 0;
}
