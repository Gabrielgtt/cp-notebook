#include <bits/stdc++.h>
#define MAXN 5100
#define MOD 1000000007
using namespace std;

int n, poss[MAXN], pai[MAXN];
pair <char, int> info[MAXN];


int main(){
	cin >> n;

	char letra;
	long long int res = 1, validos = 0, ctrl = 0, continumS = 0, continumF = 0, fs = 0;

	for (int i=0; i<n; i++){
		cin >> letra;

		if (letra == 'f'){
			if (continumS) {
				res = ((res % MOD) * (fs % MOD)) % MOD;
			} 

			continumS = 0;
			continumF++;
			fs++;

		} else if (letra == 's') {

			if (continumF == 0){
				if (continumS == 1){
					res = ((res % MOD) * (fs % MOD)) % MOD;
				} else if (continumS > 1){
					res = ((res % MOD) * ((fs-1) % MOD)) % MOD;
				}
			}

			continumF = 0;
			continumS++;
		}
	}

	cout << res << endl;

	return 0;
}
