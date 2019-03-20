#include <bits/stdc++.h>
using namespace std;

struct node{
	bool end = false;
	struct node* letras[15];
} *root;

void init(){
	root = new node();
	root->end = false;
}

void insert(const string &word){
	node* curr = root;
	for (int i=0; i<word.size(); i++){
		int letra = word[i] - '0';
		if (curr->letras[letra] == NULL){
			curr->letras[letra] = new node();
			curr->letras[letra]->end = false;
		}		
		
		curr = curr->letras[letra];

		if (curr->end)
			return false;	
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;

	int n;
	string word;
	while (t--){
		cin >> n;
		init();
		bool res = true;
		for (int i=0; i<n; i++){
			cin >> word;
			if (res){
				res = insert(word);
			}
		}
		printf("%s\n", res ? "YES" : "NO");
	}

	return 0;
}