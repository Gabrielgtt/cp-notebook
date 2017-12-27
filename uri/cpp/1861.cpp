#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx,tune=native")
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	set <string> dead;

	string killer, killed, killers[100010];
	
	map <string, int> assassins;

	int index = 0;
	
	while (cin >> killer >> killed){
		if (assassins.find(killer) == assassins.end()){
			killers[index++] = killer;
		}

		assassins[killer]++;
		
		dead.insert(killed);
	}

	sort(killers, killers+index);

	printf("HALL OF MURDERERS\n");

	for (int i=0; i<index; i++){
		if (dead.find(killers[i]) == dead.end()){
			cout << killers[i] << " " << assassins[killers[i]] << endl;
		}
	}


	return 0;
}