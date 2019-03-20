#include <bits/stdc++.h>
using namespace std;

bool flag;

struct node{
	bool end;
	struct node* word[30];
} *root;

void init(){
	root = new node();
	root->end = false;
}

void add(string pal){
	node* curr = root;
	for (int i=0; i<pal.size(); i++){
		int letra = pal[i] - '0';
		if (curr->word[letra] == NULL){
			curr->word[letra] = new node();
		} else if (i == pal.size()-1 || curr->end) {
			flag = true;
			break;
		} else {
		}
		if (i == pal.size()-1) curr->end=true;
		curr = curr->word[letra];
	}
}

int main(){
	int n, m;
	string word;
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		init();
		scanf("%d", &m);
		flag = false;
		for (int j=0; j<m; j++){
			cin >> word;
			if (!flag) add(word);
		}
		if (flag) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}