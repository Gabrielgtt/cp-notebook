#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

typedef long long ll;
typedef pair <int, int>  ii;
typedef  pair <int, ii>  iii;


int main(){
	int n;
	scanf("%d", &n);
	int num;
	bool res = true;
	for (int i=0; i<n; i++){
		scanf("%d", &num);
		if (num) res = false;
	}
	printf("%s\n", res ? "EASY" : "HARD");
	return 0;
}
