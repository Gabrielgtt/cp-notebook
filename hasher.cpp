#include <bits/stdc++.h>
using namespace std;

int main() {
	char a;
	long long hash = 0;
	long long base = 123;
	long long primo = 70195183; 
	while(scanf("%c", &a) != EOF) {
		if (a == ' ' || a == '\n') continue;
		hash += (1LL * a * base) % primo;
		base *= baseasf;
		base %= primo;
	}
	printf("%lld\n", hash);

	return 0;
}
