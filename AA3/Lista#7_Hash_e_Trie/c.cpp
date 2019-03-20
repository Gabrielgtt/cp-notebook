#include <bits/stdc++.h>
using namespace std;

struct node{
	int passadas;
	struct node* letras[3];
} *root;

void init(){
	root = new node();
	root->passadas = 0;
}

int insert(const string &word){
	node* curr = root;
	int res = 0;
	for (int i=0; i<word.size(); i++){
		int letra = word[i]-'0';
		if (curr->letras[letra] == NULL){
			curr->letras[letra] = new node();
			curr->letras[letra]->passadas = 0;
		}
		curr = curr->letras[letra];
		curr->passadas++;
		res = max(res, curr->passadas*(i+1));
	}
	return res;
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
		int res = 0;
		for (int i=0; i<n; i++){
			cin >> word;
			res = max(res, insert(word));
			
		}
		printf("%d\n", res);
	}

	return 0;
}