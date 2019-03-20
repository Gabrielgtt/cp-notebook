#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int arr[MAXN], raiz, n, m, k, res[MAXN], freq[MAXN], total = 0;

struct query{
	int left, right, id;
} qs[MAXN];

bool comp(query a, query b){
	if (a.left/raiz == b.left/raiz) return a.right < b.right;
	return a.left/raiz < b.left/raiz;
}

void add(int index){
	freq[arr[index]]++;
	total += freq[arr[index] ^ k];
}

void sub(int index){
	total -= freq[arr[index] ^ k];
	freq[arr[index]]--;
}

void solve(){
	int left = 1, right = 0;
	for (int i=0; i<m; i++){
		while (left < qs[i].left) sub(left++), printf("%d %d = %d\n", left, right, total);
		while (qs[i].left < left) add(--left), printf("%d %d = %d\n", left, right, total);
		while (right < qs[i].right) add(++right), printf("%d %d = %d\n", left, right, total);
		while (qs[i].right < right) sub(right--), printf("%d %d = %d\n", left, right, total);
		printf("\n");
		res[qs[i].id] = total;
	}

	for (int i=0; i<m; i++){
		if (i > 0) printf(" ");
		printf("%d", res[i]);
	}
	printf("\n");
}


int main(){
	scanf("%d %d %d", &n, &m, &k);

	for (int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	raiz = sqrt(m);
	int de, para;
	for (int i=0; i<m; i++){
		scanf("%d %d", &de, &para);
		qs[i].left = --de;
		qs[i].right = --para;
		qs[i].id = i;
	}

	sort(qs, qs+m, comp);

	solve();
}