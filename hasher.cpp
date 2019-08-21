#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("input", "r", stdin);
#endif
	char a;
	long long hash = 0;
	long long base = 123;
	long long primo = 70195183; 
	while(scanf("%c", &a) != EOF) {
		if (a == ' ' || a == '\n') continue;
		hash += (1LL * a * base) % primo;
		base *= base;
		base %= primo;
	}
	printf("%lld\n", hash);
	return 0;
}
