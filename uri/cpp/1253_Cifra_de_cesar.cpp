#include <bits/stdc++.h>

using namespace std;

void solve(){
	string frase;
	cin >> frase;
	int x; scanf("%d", &x);
	char a;

	for (int i=0; i<frase.size(); i++){
		printf("%c", frase[i]-x > 64 ? frase[i]-x : frase[i]-x+26 );
	}
	printf("\n");
}

int main(){
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++){
		solve();
	}
	return 0;
}