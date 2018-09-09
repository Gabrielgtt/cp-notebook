#include <bits/stdc++.h>
#define MAXN 200
using namespace std;

int main(){
	long long a, b;
	cin >> a >> b;

	while (a != 0 && b != 0){
		// cout << a << " " << b << endl;
		
		if (a >= 2 * b){
			a = a % (2*b); 
		} else if (b >= 2 * a){
			b = b % (2*a); 
		} else {
			break;
		}
	}
	cout << a << " " << b << endl;
	return 0;
}