#include <bits/stdc++.h>

using namespace std;

int main(){
	int m=-1, a, pos=1;

	for (int i=1; i<=100; i++){
		scanf("%d", &a);
		if (a > m){
			m = a;
			pos = i;
		}
	}

	printf("%d\n%d\n", m, pos);

	return 0;
}