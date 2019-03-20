#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main(){
	int n, x;
	string sign;
	scanf("%d", &n);
	
	for (int i=0; i<n; i++){
		scanf("%d", &x);
		
		if (x == 0) {
			cout << "NULL\n";
		} else {
			if (x < 0){
				sign = "NEGATIVE";
			} else{
				sign = "POSITIVE";
			}
			if (x % 2 == 0){
				cout << "EVEN " << sign << endl;
			} else {
				cout << "ODD " << sign << endl;
			}
		}	
		
	}
	
	return 0;
}
