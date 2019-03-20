#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx,tune=native")
using namespace std;

int main(){
	deque <int> fila;
	ios_base::sync_with_stdio(0);cin.tie(NULL);


	int q, num, reverse = 0;
	string tipo;
	cin >> q;

	while (q--){
		cin >> tipo;
		if (tipo == "toFront"){
			cin >> num;

			if (reverse){
				fila.push_back(num);
			} else {
				fila.push_front(num);
			}

		} else if (tipo == "push_back"){
			cin >> num;
			if (reverse){
				fila.push_front(num);
			} else {
				fila.push_back(num);
			}

		} else if (tipo == "reverse"){
			reverse == 0 ? reverse = 1 : reverse = 0;

		} else if (fila.empty()){
			cout << "No job for Ada?" << endl;

		} else if (tipo == "front"){
			if (reverse){
				cout << fila.back() << endl;
				fila.pop_back();				
			} else {
				cout << fila.front() << endl;
				fila.pop_front();				
			}
			
		} else if (tipo == "back"){
			if (reverse){
				cout << fila.front() << endl;
				fila.pop_front();				
			} else {
				cout << fila.back() << endl;
				fila.pop_back();				
			}
		}
	}
}