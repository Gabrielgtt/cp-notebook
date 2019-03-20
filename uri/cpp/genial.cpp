#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n, passos;
	cin >> n >> passos;
	long long q;
	long long x = 1, y = 1;
	// cout << "comeco passos = " << passos << endl << endl;

	map <long long, long long> quadrante;
	quadrante[1] = 1;
	quadrante[2] = 2;
	quadrante[3] = 3;
	quadrante[4] = 4;
	long long num;
	for (long long i = n; i>=2; i/=2){
		num = (i/2) * (i/2);
		q = (passos / num) + (passos % num > 0);
		
		if (i != 2){
			passos %= num;
			if (passos == 0) passos = num;			
		}

		// cout << "q = " << q << endl;
		// cout << "quadrante = " << quadrante[q] << endl;
		// cout << "faltam passos = " << passos << endl << endl;

		if (quadrante[q] == 2){
			y += i/2;
		} else if (quadrante[q] == 4){
			x += i/2;
		} else if (quadrante[q] == 3){
			y += i/2;
			x += i/2;			
		}

		if (q == 1) {
			quadrante[2] = 4;
			quadrante[4] = 2;			
		} else if (q == 4){
			quadrante[1] = 3;
			quadrante[3] = 1;
		} 
		else if (q == 2){
			quadrante[1] = 1;
			quadrante[3] = 3;			
		} else if (q == 3){
			quadrante[2] = 2;
			quadrante[4] = 4;			
		}
	}
	cout << x << " " << y << endl;
}

