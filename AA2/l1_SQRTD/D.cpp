#include <bits/stdc++.h>
#define MAXN 200010
#define MAXQ 200010
#define ll long long int
#define f first
#define s second
using namespace std;

int n, q, raiz;

struct query{
	int left, right, index;
};

bool compare(query a, query b){
	if (a.left/raiz != b.left/raiz) return a.left/raiz < b.left/raiz;
	return a.right > b.right;
}

ll line[MAXN], freq[1000010], qs[MAXQ];

int main(){
	scanf("%d %d", &n, &q);
	query atual[MAXQ];

	for (int i=0; i<n; i++){
		cin >> line[i];
	}

	raiz = sqrt(n) + 1;

	for (int i=0; i<q; i++){
		scanf("%d %d", &atual[i].left, &atual[i].right);
		atual[i].index = i;
	}

	sort(atual, atual + q, compare);

	int l=0, r=-1, k, objE, objD;

	ll power=0; 

	for (int i=0; i<q; i++){
		objD = atual[i].right-1;
		objE = atual[i].left-1;


		while (r < objD) {
			r++;
			freq[line[r]]++;
			k = freq[line[r]];
			power += ((k*k) - (k-1)*(k-1))*line[r];
		}

		while (objD < r) {
			k = freq[line[r]];
			freq[line[r]]--;
			power += ((k-1)*(k-1) - (k*k))*line[r];
			r--;
		}

		while (l < objE) {
			k = freq[line[l]];
			freq[line[l]]--;
			power += ((k-1)*(k-1) - k*k) * line[l];
			l++;
		}

		while (objE < l){
			l--;
			freq[line[l]]++;
			k = freq[line[l]];
			power += ((k*k) - (k-1)*(k-1))*line[l];
		}

		qs[atual[i].index] = power;
	}

	for (int i=0; i<q; i++){
		cout << qs[i] << endl;
	}

	return 0;
}