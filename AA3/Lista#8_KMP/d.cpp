#include <bits/stdc++.h>
#define MAXN 2000010
#define debug_arr(arr, tam) cerr << #arr << " = "; for (int i=0; i<tam; i++) printf("%d%c", arr[i], " \n"[i == tam-1])
using namespace std;

string word, linha;
int back[MAXN], freq[MAXN];
bool sufix[MAXN];

void kmp(){
	int tam = word.size();
	int res = 0;

	for (int i=1, j; i<tam; i++){
		j = back[i-1];
		while(j > 0 && word[i] != word[j]) j = back[j-1];
		if (word[i] == word[j]) j++;
		back[i] = j;
	}

	// debug_arr(back, tam);
	
	sufix[back[tam-1]] = true;

	for (int i=0; i<tam; i++)
		freq[back[i]]++;

	for (int i=tam-1; i>0; i--){
		freq[back[i-1]] += freq[i];
		if (freq[i] > 0 && sufix[i]) sufix[back[i-1]] = true, res++;
	}

	printf("%d\n", res+1);
	for (int i=1; i<=tam; i++){
		if (sufix[i])
			printf("%d %d\n", i, freq[i]+1);
	}

	printf("%d %d\n", tam, 1);
}

int main(){
	ios::sync_with_stdio(false);

	cin >> word;
	linha = word;

	kmp();

	return 0;
}