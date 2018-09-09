#include <bits/stdc++.h>
#define MAXN 10001
using namespace std;

struct node{
	bool end;
	int numLets;
	struct node* letters[30];
} *root;

void init(){
	root = new node();
	root->end = false;
	root->numLets = 0;
}

void add(string word){
	node* curr = root;
	int len = word.size();
	for (int i=0; i<len; i++){
		int letra = word[i] - 'a';
		if (curr->letters[letra] == NULL){
			curr->letters[letra] = new node();
			curr->numLets++;
		}
		curr = curr->letters[letra];
	}
	curr->end = true;
}

int query(string word){
	node* curr = root;
	int ops, len = ops = word.size();
	for (int i=0; i<len; i++){
		int letra = word[i]-'a';
		if (curr->numLets == 1 && !curr->end && i!=0){
			// printf("%c %d %d\n", letra+'a', i, curr->end;	
			ops--;
		} 
		curr = curr->letters[letra];
	}
	return ops;
}

int main(){
	int n;
	while (cin >> n){
		init();
		vector <string> words;
		string word;
		for(int i=0; i<n; i++){
			cin >> word;
			words.push_back(word);
			add(word);
		}
		double res = (double) 0;
		for (int i=0; i<n; i++){
			double aux = (double) query(words[i]);
			// printf(">> %.2lf\n", aux);
			res += aux;
		}
		printf("%.2lf\n", res/(double)n);
	}
	return 0;
}