#include <bits/stdc++.h>
#define ii pair <int, int>
using namespace std;

// ------------------------------------------------------------------------------
int n;
void maxQueue(int tam, int arr[]) {
	deque <ii> que;
	for (int i=0; i<n; i++) {
		while(!que.empty() && i - que.front().second >= tam) que.pop_front();
		while(!que.empty() && que.back().first < arr[i]) que.pop_back();
		que.emplace_back(arr[i], i);
	}
}
// ------------------------------------------------------------------------------ 8530822201
