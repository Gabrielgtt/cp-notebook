struct node {
	bool end;
	node *prox[27];

} *root = new node();

void insert(const string& word) {
	node *curr = root;
	for (char l : word) {
		if (!curr->prox[l-'a']) curr->prox[l-'a'] = new node();
		curr = curr->prox[l-'a'];
	}
	curr->end = true;
}
