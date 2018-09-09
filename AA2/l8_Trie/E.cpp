#include <bits/stdc++.h>
using namespace std;

map <char, string> dic; 

string convert(const string &word){
	string converted = "";
	for (int i=0; i<word.size(); i++){
		converted += dic[word[i]];
	}
	return converted;
}

struct node{
	bool end;
	struct node* letters[3];
} *root;

void init(){
	root = new node();
	root->end = false;
}

void add(const string &word){
	node* curr = root;
	int letra;
	for (int i=0; i<word.size(); i++){
		letra = word[i] - '-';
		if (curr->letters[letra] == NULL) curr->letters[letra] = new node();
		curr = curr->letters[letra];
	}
	curr->end = true;
}

bool inTrie(const string &word){
	node* curr = root;
	int letra;
	for (int i=0; i<word.size(); i++){
		letra = word[i] - '-';
		if (curr->letters[letra] == NULL) return false;
		curr = curr->letters[letra];
	}
	return curr->end;
}

int main(){
	char letter;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string word, conv;
	map <string, string> deVolta;
	for (int i=0; i<26; i++){
		cin >> letter >> word;
		dic[letter] = word;
	}
	int n;
	cin >> n;
	init();
	for (int i=0; i<n; i++){
		cin >> word;
		conv = convert(word);
		deVolta[conv] = word;
		add(conv);
	}
	vector<string> ans;
	bool flag;
	while (cin >> n && n != 0){
		ans.clear();
		flag = false;
		for (int i=0; i<n; i++){
			cin >> word;
			if (flag) continue;
			if (inTrie(word)){
				ans.push_back(deVolta[word]);
			} else {
				cout << word << " not in dictionary.";
				flag = true; 
			}
		}
		if (!flag){
			for (int i=0; i<ans.size(); i++){
				if (i > 0) cout << " ";
				cout << ans[i];
			}
		}
		cout << endl;
	}
	return 0;
}
