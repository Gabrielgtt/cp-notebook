#include <bits/stdc++.h>
using namespace std;

struct node {
    bool end;
	int ne[27];
    node() {
        end = false;
        memset(ne, -1, sizeof ne);
    }
};

vector <node> trie({node()});

void insert(const string& word) {
    int a = 0;
	for (char l : word) {
		if (trie[a].ne[l-'a'] == -1) {
            trie[a].ne[l-'a'] = trie.size();
            trie.emplace_back(node());
        }
		a = trie[a].ne[l-'a'];
	}
    trie[a].end = true;
}

int main() {
	string t = "teste", o = "outro";
	insert(t);
	insert(o);
	int a = 0;
	for (char l : t) a = trie[a].ne[l-'a'];
	assert(trie[a].end);
	return 0;
}
