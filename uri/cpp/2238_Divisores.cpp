#include <bits/stdc++.h>

using namespace std;

int main(){
	int a, b, c, d;

	scanf("%d %d %d %d", &a, &b, &c ,&d);

	int res = -1, raiz = sqrt(c);
	vector<int> divs;

	for (int i = 1; i <= raiz; i++){
		if (c % i == 0){
			divs.push_back(i); 
			divs.push_back(c/i);
		}
	}

	sort(divs.begin(), divs.end());

	for (int i=0; i<divs.size(); i++){
		if (divs[i] % a == 0 && divs[i] % b != 0 && d % divs[i] != 0){
			res = divs[i];
			break;
		}
	}


	printf("%d\n", res);

}