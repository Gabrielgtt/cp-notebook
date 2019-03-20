#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	string pal;
	cin >> n;
	cin >> pal;

	for (int i=0; i<pal.size()-1; i++){
		if (pal[i] == pal[i+1] && pal[i] != '?'){
			printf("No\n");
			return 0;
		}
	}


	int res = 0;  
	for (int i=0; i<pal.size(); i++){
		if (pal[i] == '?'){
			res++;
		}
	}
	if (!res) {
		printf("No\n");
		return 0;
	}

	bool f1 = true, f2 = false;
	for (int i=1; i<pal.size()-1; i++){
		if (pal[i] == '?'){
			if (pal[i-1] != pal[i+1] && pal[i-1] != '?' && pal[i+1] != '?'){
				f2 = true;
			} else {
				f1 = false;
				break;
			}
		}
	}

	if (pal[0] == '?' || pal[pal.size()-1] == '?'){
		f1 = false;
	}

	if (f1 && f2){
		printf("No\n");
		return 0;
	}

	printf("Yes\n");
	return 0;
}