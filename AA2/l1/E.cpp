#include <bits/stdc++.h>
#define MAXN 100010
#define MAXQ 100010
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

int line[MAXN], qs[MAXQ], freqA[MAXN];

int main(){
	map <int, int > freq;
	scanf("%d %d", &n, &q);
	query atual[MAXQ];

	for (int i=0; i<n; i++){
		scanf("%d", &line[i]);
		
		if (line[i] > MAXN) {
			if (freq.find(line[i]) == freq.end()){
				freq.insert(pair <int, int > (line[i], 0));
			}
		}
	}

	raiz = sqrt(n) + 1;

	for (int i=0; i<q; i++){
		scanf("%d %d", &atual[i].left, &atual[i].right);
		atual[i].index = i;
	}

	sort(atual, atual + q, compare);

	int l=0, r=-1, k, objE, objD;

	int res=0, agora; 

	for (int i=0; i<q; i++){
		objD = atual[i].right-1;
		objE = atual[i].left-1;


		while (r < objD) {
			r++;			
			if (line[r] > MAXN)	agora = freq.find(line[r])->second; 
			else agora = freqA[line[r]];

			if (agora == line[r]) res--;
			if (line[r] > MAXN) freq[line[r]] += 1;
			else freqA[line[r]] += 1;
			if (agora+1 == line[r]) res++;
		}

		while (objD < r) {
			if (line[r] > MAXN)	agora = freq.find(line[r])->second; 
			else agora = freqA[line[r]];
			
			if (agora == line[r]) res--;
			if (line[r] > MAXN) freq[line[r]] -= 1;
			else freqA[line[r]] -= 1;
			if (agora-1 == line[r]) res++;
			r--;
		}

		while (l < objE) {
			if (line[l] > MAXN)	agora = freq.find(line[l])->second; 
			else agora = freqA[line[l]];
			if (agora == line[l]) res--;
			if (line[l] > MAXN) freq[line[l]] -= 1;
			else freqA[line[l]] -= 1;
			if (agora-1 == line[l]) res++;
			l++;
		}

		while (objE < l){
			l--;
			if (line[l] > MAXN)	agora = freq.find(line[l])->second; 
			else agora = freqA[line[l]];
			if (agora == line[l]) res--;
			if (line[l] > MAXN) freq[line[l]] += 1;
			else freqA[line[l]] += 1;
			if (agora+1 == line[l]) res++;
		}

		qs[atual[i].index] = res;
	}

	for (int i=0; i<q; i++){
		cout << qs[i] << endl;
	}

	return 0;
}