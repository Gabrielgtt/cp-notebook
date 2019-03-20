#include <bits/stdc++.h>
#define MAXN 600000
#define ll long long
using namespace std;

vector <double> raios;

int main(){
	freopen("input", "r", stdin);
	int c, t;
	double num;
	scanf("%d %d", &c, &t);
	for (int i=0; i<c; i++){
		scanf("%lf", &num);
		raios.push_back(num);
	}

	double x, y;
	ll pontos = 0;
	for (int i=0; i<t; i++){
		scanf("%lf %lf", &x, &y);
		double dist = sqrt((x*x) + (y*y));
		ll index = lower_bound(raios.begin(), raios.end(), dist) - raios.begin();
		pontos += c - index;
	}

	printf("%lld\n", pontos);
	return 0;
}