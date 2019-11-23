#include <bits/stdc++.h>
using namespace std;

// Retorna quantas raízes e deixa as raízes no out
// ----------------------------------------------------------------------------- 
int quadRoots(double a, double b, double c, pair<double,double> &out) {
	assert(a != 0);
	double disc = b*b - 4.0*a*c;
	if (disc < 0) return 0;
	double sum = (b >= 0) ? -b-sqrt(disc) : -b+sqrt(disc);
	out = {sum/(2.0*a), sum == 0 ? 0 : (2.0*c)/sum};
	return 1 + (disc > 0);
}
// ----------------------------------------------------------------------------- 7540185169

int main () {
	pair <double, double> raizes;
	printf("temos %d raizes\n", quadRoots(1, 6, -7, raizes));
	printf("%.14f %.14f\n", raizes.first, raizes.second);
	return 0;
}
