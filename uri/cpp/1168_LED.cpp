#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, res;
	cin >> n;
	string num;

	while (n--){
		res = 0;
		cin >> num;

		for (int i = 0; i< num.size(); i++){
			if (num[i] == '0') res+=6;
			else if (num[i] == '1') res+=2;
			else if (num[i] == '2') res+=5;
			else if (num[i] == '3') res+=5;
			else if (num[i] == '4') res+=4;
			else if (num[i] == '5') res+=5;
			else if (num[i] == '6') res+=6;
			else if (num[i] == '7') res+=3;
			else if (num[i] == '8') res+=7;
			else if (num[i] == '9') res+=6;
		}

		printf("%d leds\n", res);
	}



	return 0;
}