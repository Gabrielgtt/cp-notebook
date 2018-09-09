#include <bits/stdc++.h>
using namespace std;

int main(){
	string alfabeto, palavra;
	map <char, char> codigo;
	cin >> alfabeto >> palavra;

	for (int i ='a'; i<='z'; i++){
		codigo[(char) i ] = alfabeto[(char)(i-'a')]; 
	}

	for (int i=0; i<palavra.size(); i++){
		printf("%c", codigo[palavra[i]]);
	}
	printf("\n");

	return 0;
}