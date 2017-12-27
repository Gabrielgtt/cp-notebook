#include <bits/stdc++.h>

using namespace std;

void solve(int n){
	set <int> saida[26];
	vector<int> ant;
	int flag[26], res=0, num;
	memset(flag, 0, sizeof flag);

	scanf("%d", &num);
	ant.push_back(num);

	for (int i=0; i<n-1; i++){
		scanf("%d", &num);

		for (int j=0; j<ant.size(); j++){
			saida[num].insert(ant[j]);
		}

		ant.push_back(num);
	}

	for (int i=0; i<n; i++){
		scanf("%d", &num);
		flag[num] = 1;
		for (int j=1; j<=n; j++){
			if (flag[j] == 0 && saida[num].find(j) != saida[num].end()){
				res++;				
			}
		}
	}

	printf("%d\n", res);
}

int main(){
	int n;
	while (scanf("%d", &n) != EOF){
		solve(n);
	}
	return 0;
}