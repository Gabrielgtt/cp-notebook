#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define ii pair <int, int>
#define INF 1e9
#define MOD 7901
#define pb push_back
#define MAXN 2000
#define debug(x) cerr << #x << " = " << x << endl
#define debug_arr(x, tam) cerr << #x << " = "; for (int i=0;i<tam;i++) cout << x[i] << " "; printf("\n")
using namespace std;

int com[MAXN];
char res[MAXN];

int main(){
	int n;
	scanf("%d", &n);

	int beg = 0;
	int pot = 1;
	int pulo = 2;
	for (int i='a'; i<='z'; i++){
		com[i-'a'] = beg;
		if (beg > 1000) break;
		for (int j=com[i-'a']; j<=1000; j+=pulo){
			res[j] = i;
		}
		beg += pot;
		pot *= 2;
		pulo *= 2;
	}

	printf("%c\n", res[n-1]);

	return 0;
}