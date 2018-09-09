#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e17;
const int MAXN = 1000100;

typedef pair <int, int> ii;

char num1[MAXN];
char num2[MAXN];

int main(){
	int n;
	scanf("%d", &n);

	scanf("%s", num1);
	scanf("%s", num2);

	int res = 0;
	for (int i=0; i<n-1; i++){
		if (num1[i] != num2[i] && num1[i+1] != num2[i+1] && num1[i] != num1[i+1]){
			swap(num1[i], num1[i+1]);
			res++;
		} else if (num1[i] != num2[i]){
			num1[i] == num1[i] == '0' ? '1' : '0';
			res++;
		}
	}
	if (num1[n-1] != num2[n-1]) res++;
	printf("%d\n", res);
	return 0;
}