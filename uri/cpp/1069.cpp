#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	string mina;

	while (n--){
		cin >> mina;

		int esq=0, res=0;
		for (int i = 0; i < mina.size(); i++){
			if (mina[i] == '<') esq++;
			else if (mina[i] == '>' && esq > 0) res++, esq--;
		}

		printf("%d\n", res);
	}
	return 0;
}