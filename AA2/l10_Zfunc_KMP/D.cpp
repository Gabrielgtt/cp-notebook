#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

string word;
int z[MAXN], tam;
void zFunc(){
	memset(z, 0, sizeof z);
	int right = 0, left = 0, kzin;
	tam = word.size();
	for (int k=1; k<tam; k++){
		if (k > right){
			left = right = k;
			while (right < tam && word[right] == word[right-left]) right++;
			z[k] = right-left;
			right--;
		} else {
			kzin = k - left;
			if (z[kzin] < right - k + 1){
				z[k] = z[kzin];
			} else {
				left = k;
				while (right < tam && word[right] == word[right-left]) right++;
				z[k] = right - left;
				right--;  
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	bool flag;
	while (cin >> word){
		if (word == "*") break;
		zFunc();
		flag = true;
		for (int i=1; i<tam; i++){
			if ((z[i] + i == tam) && (tam % i == 0)){
				cout << tam/i << endl;
				flag = false;
				break;
			}
		}
		if (flag) cout << 1 << endl;
	}

	return 0;
}