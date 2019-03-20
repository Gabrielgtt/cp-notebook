#include <bits/stdc++.h>
using namespace std;

#define MAXN 100010

int intervalo, n, fim_intervalo, counter;

struct sq {
	int v, index;
} sqrtd[MAXN], arr[MAXN];

int bsearch(int left, int right, int v) {
	int mid = (left+right)/2;
	counter += 1;

	if(counter > 20) return mid;

	if( left < right ) {
		if( sqrtd[mid].v <= v ) {
			if( sqrtd[mid+1].v > v and mid+1 < n ) return mid;
			return bsearch(mid+1, right, v);
		}
		if( sqrtd[mid].v > v ) return bsearch(left, mid, v);
	}

	if( sqrtd[mid].v > v ) mid--;
	return mid;
}

void insere_ord(int previous, int val) {
	sqrtd[ previous ].v = val;
	bool para;
	int i = sqrtd[previous].index;

	while(true) {
		para = true;
		if( sqrtd[ previous ].v > sqrtd[ previous+1 ].v and previous+1 < n and previous/intervalo == (previous+1)/intervalo ) {
			arr[ sqrtd[previous+1].index ].index = previous; 
			swap( sqrtd[previous], sqrtd[previous+1] );

			previous++;
			para = false;
		}
		else {
			if( sqrtd[ previous ].v < sqrtd[ previous-1 ].v and previous-1 >= 0 and previous/intervalo == (previous-1)/intervalo ) {
				arr[ sqrtd[previous-1].index ].index = previous; 
				swap( sqrtd[previous], sqrtd[previous-1] );

				previous--;
				para = false;
			}
		}

		if(para) break;
	}

	arr[ i ].index = previous;
}

int range_query(int l, int r, int v) {
	int i, ans = 0, aux;

	for(i=l; i <= r; i++) {
		if( i%intervalo == 0 and r >= (i+intervalo) - 1 ) {

			fim_intervalo = (i+intervalo) - 1;
			counter = 0;
			aux = bsearch( i, i+intervalo-1, v );
			ans += aux - i + 1;
			i += intervalo-1;
		}
		else {
			if(arr[i].v <= v) {
				ans += 1;
			}
		}
	}

	return ans;
}

bool compare(sq f, sq s) {
	if( f.index / intervalo == s.index / intervalo ) return f.v < s.v;
	return f.index / intervalo < s.index / intervalo;
}

int main() {

	int queries, i, l, r, indice, val, aux, j;
	char op;

	cin >> n >> queries;
	intervalo = sqrt(n);

	for(i=0; i < n; i++) {
		cin >> arr[i].v;
		sqrtd[i].v = arr[i].v, sqrtd[i].index = i;
	}

	sort(sqrtd, sqrtd+n, compare);
	for(i=0; i < n; i++) arr[ sqrtd[i].index ].index = i;

	for(i=0; i < queries; i++) {
		cin >> op;

		if(op == 'C') {
			cin >> l >> r >> val;
			l--, r--;

			printf("%d\n", range_query(l, r, val));
		}
		else {
			cin >> indice >> val;
			indice--;

			aux = arr[indice].index;
			arr[indice].v = val;

			insere_ord(aux, val);
		}

	}

	return 0;
}