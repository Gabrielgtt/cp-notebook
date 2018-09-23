#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

typedef long long ll;
typedef pair <int, int>  ii;
typedef  pair <int, ii>  iii;

const int MAXN = 1000;

char num[MAXN];
int n;

int main(){
	scanf("%d", &n);

	scanf("%s", num);
	int soma = 0;
	bool res = false;
	for (int i=0; i<n; i++){
		soma += num[i] - '0';

		int suma = 0;
		for (int j=i+1; j<n; j++){
			suma += num[j] - '0';
			if (suma > soma) suma -= soma;
		}

		if (soma == suma) res = true;
	}

	printf("%s\n", res ? "YES" : "NO");

	return 0;
}