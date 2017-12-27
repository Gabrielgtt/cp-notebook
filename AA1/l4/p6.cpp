#include <bits/stdc++.h>
#define ull unsigned long long int
using namespace std;

ull combs(int n, int m){
    ull resp = 1;
 
    if(m>n-m) m=n-m;
    
    for(int i = 0; i < m ; i++) resp = resp*(n-i)/(i+1);
    
    return resp;
}

int main(){
	int t;
	int m, c;
	scanf("%d", &t);

	while (t--){
		scanf("%d %d", &m, &c);
		m--, c--;
		cout << combs(m, c) << endl;
	}


	return 0;
}