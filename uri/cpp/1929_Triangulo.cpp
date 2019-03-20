#include <bits/stdc++.h>

using namespace std;

int main(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int res = 0;
	if (a+b>c and a+c>b and b+c>a){
		res = 1;
	} else if (d+b>c and d+c>b and b+c>d){
		res = 1;
	} else if (a+d>c and a+c>d and d+c>a){
		res = 1;
	} else if (a+b>d and a+d>b and b+d>a){
		res = 1;
	}

	if (res) printf("S\n");
	else printf("N\n");

	return 0;
}
