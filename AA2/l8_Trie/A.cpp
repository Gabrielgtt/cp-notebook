#include <bits/stdc++.h>
using namespace std;

int k, bad[30];

struct node{
	bool end;
	struct node* letters[30];
} *root;

void init(){
	root = new node();
	root->end = false;
}

int insert(const string &word){
	int bads, letra, res = 0;
	node* curr;
	for (int beg = 0; beg<word.size(); beg++){
		curr = root;
		bads = 0;
		for (int i=beg; i<word.size(); i++){
			letra = word[i]-'a';
			if (curr->letters[letra] == NULL) curr->letters[letra] = new node();
			if (bad[letra]) bads++;
			if (bads <= k && !curr->letters[letra]->end) res++, curr->letters[letra]->end = true;
			curr = curr->letters[letra];
		}
	}
	return res;
}

int main(){
	string word, bads;
	cin >> word >> bads >> k;
	for (int i=0; i<bads.size(); i++){
		if (bads[i] == '1') bad[i] = 0;
		else bad[i] = 1;
	}
	init();
	printf("%d\n", insert(word));
	return 0;
}