#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define ii pair <int, int>
#define f first
#define s second
#define INF 1e9
#define MAXN 100010
#define MAXLOG 19
using namespace std;

vector < pair <char, char> > res;

void solve(int count, char source, char dest, char inter){
	if (count == 1){
		res.push_back({source, dest});
	} else {
		solve(count-1, source, inter, dest);
		solve(1, source, dest, inter);
		solve(count-1, inter, dest, source);
	}
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);

	solve(n, 'A', 'C', 'B');

	if (k < res.size()){
		printf("N\n");
	} else {
		printf("Y\n");
		for (int i=0; i<res.size()-1; i++){
			printf("%c %c\n", res[i].f, res[i].s);
			k--;
		}

		char orige = res[res.size()-1].f;
		while (k > 1){
			printf("%c %c\n", orige, orige == 'A' ? 'B' : 'A');
			orige = orige == 'A' ? 'B' : 'A';
			k--;
		}

		printf("%c %c\n", orige, 'C');
	}

	return 0;
}
