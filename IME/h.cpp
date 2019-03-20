#include <bits/stdc++.h>
#define MAXN
#define ll long long
#define ii pair <int, int>
#define f first
#define s second
#define pb push_back
using namespace std;

int main(){
	ll n, a, p;

	cin >> n >> a >> p;

	ll aux1 = a * p;
	ll aux2 = a * (100-p);
	double outro1 = ((double)aux1) / 100.0;
	double outro2 = ((double)aux2) / 100.0;

	double res =  n;
	res += outro1 - outro2; 

	printf("%.8f\n", res);

	return 0;
}