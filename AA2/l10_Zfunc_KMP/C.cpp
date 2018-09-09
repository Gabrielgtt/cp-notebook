#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
	
string pattern, text;
int tam, back[MAXN], tam2;

int kmpPreProcess(){
	int i = 0, j = -1; 
	back[0] = -1;
	bool flag = false;
	while (i < tam2){
		while (j >= 0 && pattern[i] != pattern[j]) j = back[j];
		j++, i++;
		back[i] = j;
		if (j == tam) j = back[j], printf("%d\n", i-tam-tam-1), flag = true;
	}
	if (!flag) printf("\n");
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	while (cin >> tam){
		memset(back, 0 , sizeof back);
		cin >> pattern >> text;
		tam2 = tam + 1 + text.size();
		pattern += "$" + text;
		kmpPreProcess();
	}
	return 0;
}