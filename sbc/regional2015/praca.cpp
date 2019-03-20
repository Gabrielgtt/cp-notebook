#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

typedef pair <int, int> ii;

const int MAXN = 30000;

ii points[MAXN];

int n;
int solve(int idx, int y){
	int upper = 1e9;
	int low = -1e9;

	while(points[idx-1].f == points[idx].f && idx < n) idx++;

	int res = 0;
	for (int i=idx; i<n; i++){
		int yy = points[i].s;
		if (yy == y) continue;

		if (yy > y){	
			if (yy < upper){
				res++;
				upper = yy;
			}

		} else {
			if (yy > low){
				res++;
				low = yy;
			}
		}
	}

	return res;
}

int main(){
	scanf("%d", &n);

	for (int i=0; i<n; i++){
		scanf("%d %d", &points[i].f, &points[i].s);
	}

	sort(points, points+n);

	int res = 0;
	for (int i=0; i<n-1; i++){
		res += solve(i+1, points[i].s);
	}

	printf("%d\n", res);

	return 0;
}