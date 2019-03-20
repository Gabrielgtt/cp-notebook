#include <bits/stdc++.h>
#define MAXN 2000010
#define debug_arr(arr, tam) cerr << #arr << " = "; for (int i=0; i<tam; i++) printf("%d%c", arr[i], " \n"[i == tam-1]);
using namespace std;

string word;
string linha;

int back[MAXN], freq[MAXN];
bool sufix[MAXN];

void kmp(){
	int tam = word.size();
	for (int i=1, j; i<tam; i++){
		j = back[i-1];
		while (j > 0 && word[i] != word[j]) j = back[j-1];
		if (word[i] == word[j]) j++;
		back[i] = j;
		freq[back[i]]++;
	}

	sufix[back[tam-1]] = true;
	
	for (int i=tam-1; i>0; i--){
		freq[back[i-1]] += freq[i];
		if (freq[i] > 0 && sufix[i]) sufix[back[i-1]] = true;
	}

	for (int i=tam; i>=1; i--){
		if (freq[i]+1 >= 3 && sufix[i]){
			cout << word.substr(0, i) << endl;
			return;
		}
	}

	cout << "Just a legend" << endl;
}


int main(){
	ios::sync_with_stdio(false);
	cin >> word;
	kmp();
	return 0;
}