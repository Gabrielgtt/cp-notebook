#include <bits/stdc++.h>
#define MAXN 300010
using namespace std;

string reversa, linha, original;
int back[MAXN], n;
void revert(){
	for (int i=0; i<reversa.size()/2; i++){
		swap(reversa[i], reversa[n-i-1]);
	}
}

void kmp(){
	memset(back, 0, sizeof back);
	int i=0, j = -1, tamTotal = linha.size();
	back[0] = -1;
	while(i < tamTotal){
		while (j >= 0 && linha[i] != linha[j]) j = back[j];
		i++, j++;
		back[i] = j;
	}
	cout << original;
	for (int i=n-1-back[tamTotal]; i>=0; i--){
		cout << original[i];
	}
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> reversa){
		original = reversa;
		n = original.size();
		revert();
		linha = reversa + "$" + original;
		kmp();
	}
	return 0;
}