#include <bits/stdc++.h>
#define iii pair < pair <int, int >, int >
#define MAXN 2000010
#define ff first.first 
#define fs first.second
using namespace std;

iii query[MAXN];
int arr[30010], freq[1000001], n, q, raiz, res[MAXN];

bool SQRTord(iii a, iii b){
	if (a.ff/raiz != b.ff/raiz) return a.ff/raiz < b.ff/raiz;
	return a.fs > b.fs;
}


int main(){
	scanf("%d", &n);

	for (int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}

	raiz = (int) sqrt (n + .0) + 1;

	scanf("%d", &q);

	for (int i=0; i<q; i++){
		scanf("%d %d", &query[i].ff, &query[i].fs);
		query[i].second = i;
	}

	sort (query, query+q, SQRTord);

	int l = 0, r = -1, numsDif = 0, objR, objL;

	for (int i=0; i<q; i++){
		objR = query[i].fs-1;
		objL = query[i].ff-1;


		while (objR > r) {
			r++;
			freq[arr[r]]++;
			if (freq[arr[r]] == 1) numsDif++;
		}

		while (objR < r) {
			freq[arr[r]]--;
			if (freq[arr[r]] == 0) numsDif--;
			r--;
		}

		while (objL > l) {
			freq[arr[l]]--;
			if (freq[arr[l]] == 0) numsDif--;
			l++;
		}

		while (objL < l) {
			l--;
			freq[arr[l]]++;
			if (freq[arr[l]] == 1) numsDif++;
		}


		res[query[i].second] = numsDif;
	}

	for (int i=0; i<q; i++){
		printf("%d\n", res[i]);
	}

}