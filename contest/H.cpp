#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define ii pair <int, int>
#define f first
#define s second
#define INF 1e9
#define MAXN 30010
using namespace std;

int arr[MAXN], res[MAXN], freqNums[MAXN], trans[MAXN], freq[MAXN];
int raiz;
int n, q;

set <int> salve;

struct query{
	int left, right, id;
} qs[MAXN];

bool comp(query a, query b){
	if (a.left/raiz == b.left/raiz) return a.right < b.right;
	return a.left/raiz < b.left/raiz;
}

void add(int index){	
	freq[arr[index]]++;

	freqNums[freq[arr[index]]]++;

	if (freqNums[freq[arr[index]]] >= freq[arr[index]]){
		salve.insert(freq[arr[index]]);
	}
}

void sub(int index){
	freqNums[freq[arr[index]]]--;
	
	if (freqNums[freq[arr[index]]] < freq[arr[index]]){
		if (salve.count(freq[arr[index]])){
			salve.erase(freq[arr[index]]);
		}
	}

	freq[arr[index]]--;
}

void solve(){
	int left = 1, right = 0;
	for (int i=0; i<q; i++){
		while (left < qs[i].left) sub(left++);
		while (qs[i].left < left) add(--left);
		while (right < qs[i].right) add(++right);
		while (qs[i].right < right) sub(right--);

		res[qs[i].id] = *salve.rbegin();
	}

	for (int i=0; i<q; i++){
		printf("%d\n", res[i]);
	}
}


int main(){
	scanf("%d %d", &n, &q);

	raiz = sqrt(n)+1;

	for (int i=0; i<n; i++){
		scanf("%d", &arr[i]);
		trans[i] = arr[i];
	}

	map <int, int> cores;
	int corAux = 1;
	sort(trans, trans+n);
	for (int i=0; i<n; i++){
		if (cores.count(trans[i]) == 0){
			cores[trans[i]] = corAux++;
		}
	}

	for (int i=0; i<n; i++){
		arr[i] = cores[arr[i]];
	}


	for (int i=0; i<q; i++){
		scanf("%d %d", &qs[i].left, &qs[i].right);
		qs[i].left--;
		qs[i].right--;
		qs[i].id = i;
	}

	sort(qs, qs+q, comp);

	solve();

	return 0;
}
