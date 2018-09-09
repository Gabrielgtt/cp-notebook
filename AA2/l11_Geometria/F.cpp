#include <bits/stdc++.h>
#define MAXN 100010
#define PI 3.14159265358979323846
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<pair <double, int>> tans;
	int x, y;
	for (int i=0; i<n; i++){
		scanf("%d %d", &x, &y);
		printf("%.16lf\n", (atan2(y, x)));
		tans.emplace_back(make_pair((atan2(y, x) ), i));
	}
	// printf("\n\n");

	sort(tans.begin(), tans.end());

	double difAtual = 1000000000;
	int c1=-1, c2=-1;

	for (int i=0; i<n-1; i++){
		if (difAtual >= abs(tans[i].first - tans[i+1].first)) difAtual = abs(tans[i].first - tans[i+1].first), c1 = tans[i].second, c2 = tans[i+1].second;
		printf(" %d %d   %lf\n", c1, c2, difAtual);
	}

	if ((tans[0].first < 0 != tans[n-1].first < 0) && tans[0].first != PI && tans[0].first  != 0.00 && tans[n-1].first  != 0.00 && tans[n-1].first != PI){
			double dist1 = min(PI - abs(tans[0].first), abs(tans[0].first));
			double dist2 = min(PI - abs(tans[n-1].first), abs(tans[n-1].first));
			if (difAtual > dist1 + dist2) difAtual = dist1 + dist2, c1 = tans[0].second, c2 = tans[n-1].second;

	} else if (difAtual > abs(abs(tans[0].first) - abs(tans[n-1].first))) c1 = tans[0].second, c2 = tans[n-1].second;

	printf(" %d %d   %lf\n", c1, c2, difAtual);

	printf("%d %d\n", c1+1, c2+1);

	return 0;
}