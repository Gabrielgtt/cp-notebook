#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	string frase;
	cin >> n;
	cin.ignore();

	while (n--){
		getline(cin, frase);
		// cout << "Essa e a frase: ";

		for (int i = (frase.size()/2)-1; i>=0; i--){
			printf("%c", frase[i]);
			// cout << frase[i];
		}

		for (int i = frase.size()-1; i>(frase.size()/2)-1; i--){
			printf("%c", frase[i]);
			// cout << frase[i];
		}

		printf("\n");
		// cout << endl;
	}



	return 0;
}