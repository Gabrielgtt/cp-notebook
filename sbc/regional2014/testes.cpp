#include <bits/stdc++.h>
#define iii pair< int, pair <int, int> >
#define mp make_pair
#define MAXN 100
using namespace std;
	
int fastExpo(int num, int e){
	if (e == 0 || e == 1) return 1;

	if (e & 1) return num * fastExpo(e-1);
	else

}

int main(){

}