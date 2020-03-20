#include <bits/stdc++.h>
using namespace std;

struct node {
	bool end;
	node *ne[27];
} *root = new node();

// O(n) - Insert wo in trie
void insert(const string& wo) {
	node *cu = root;
	for (char l : wo) {
		if (!cu->ne[l-'a']) cu->ne[l-'a'] = new node();
		cu = cu->ne[l-'a'];
	}
	cu->end = true;
}

int main() {
	string t = "teste", o = "outro";
	insert(t);
	insert(o);
	node *cu = root;
	for (char l : t) cu = cu->ne[l-'a'];
	assert(cu->end);
	return 0;
}
