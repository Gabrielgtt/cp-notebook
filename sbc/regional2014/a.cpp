#include <bits/stdc++.h>
using namespace std;

int main(){
	double a, b;
	scanf("%lf %lf", &a, &b);
	double tempDecorrido = (a * b) / (b - a);
	printf("%.0f\n", ceil(tempDecorrido / a));
	return 0;
}