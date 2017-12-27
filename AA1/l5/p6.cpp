#include <bits/stdc++.h>
using namespace std;
	
int arr[200];

int main(){
	int n;
	string pal;

	cin >> n;
	cin >> pal;

	for (int i=0; i<pal.size(); i++){
		arr[tolower(pal[i])] = 1;
	}

	for (int i='a'; i<='z'; i++){
		if (arr[i] == 0){
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");
	return 0;

}