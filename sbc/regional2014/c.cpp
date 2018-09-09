#include <bits/stdc++.h>
using namespace std;

int m, n, res = -1;
struct planeta{
	int x, y, z;
} planetas[10010];

struct plano{	
	int a, b, c, d;
	int posicao(planeta p){
		return ((p.x * a) + (p.y * b) + (p.z * c) - d);
	}
} planos[510];

struct node{
	int ends = 0;
	struct node* outro[3];
} *root;

void init(){
	root = new node();
	root->ends = 0;
}

int insert(int p){
	node* curr;
	curr = root;
	int prox;
	for (int i=0; i<m; i++){
		prox = planos[i].posicao(planetas[p]) < 0 ? 0 : 1;
		if (curr->outro[prox] == NULL){
			curr->outro[prox] = new node();
		}
		curr = curr->outro[prox];
		if (i == m-1) curr->ends += 1;
		res = max(curr->ends, res);
	}
}

int main(){
	scanf("%d %d", &m, &n);
	int a, b, c, d;
	for (int i=0; i<m; i++){	
		scanf("%d %d %d %d", &a, &b, &c, &d);
		planos[i].a = a;
		planos[i].b = b;
		planos[i].c = c;
		planos[i].d = d;
	}

	for (int i=0; i<n; i++){	
		scanf("%d %d %d", &a, &b, &c);
		planetas[i].x = a;
		planetas[i].y = b;
		planetas[i].z = c;
	}

	int soma;
	init();
	for (int i=0; i<n; i++){
		insert(i);
	}

	printf("%d\n", res);
	return 0;
}