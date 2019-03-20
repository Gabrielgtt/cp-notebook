#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

struct query {
	int id, L, R;

} qs[MAXN];

map <int, int> mask;
int raiz, arr[MAXN], res[MAXN], total = 0, freq[MAXN], volta[MAXN];

bool compSqrtd(query a, query b){
	if (a.L/raiz == b.L/raiz) return a.R < b.R;
	return a.L/raiz < b.L/raiz;
}

void add(int index){
	if (freq[arr[index]] == volta[arr[index]]) total--;
	freq[arr[index]]++;
	if (freq[arr[index]] == volta[arr[index]]) total++;
}

void sub(int index){
	if (freq[arr[index]] == volta[arr[index]]) total--;
	freq[arr[index]]--;
	if (freq[arr[index]] == volta[arr[index]]) total++;
}

int main(){
	int n, m, num, ctrl = 1;
	scanf("%d %d", &n, &m);
	for (int i=0; i<n; i++){
		scanf("%d", &num);
		if (mask[num]){
			arr[i] = mask[num];
		} else {
			arr[i] = mask[num] = ctrl++;
			volta[arr[i]] = num;
		}
	}
	int de, para;
	raiz = (int) sqrt(n);

	for (int i=0; i<m; i++){
		scanf("%d %d", &de, &para);
		qs[i].id = i;
		qs[i].L = --de;
		qs[i].R = --para;
	}
	
	sort(qs, qs+m, compSqrtd);

	int left = 1, right = 0;
	for (int i=0; i<m; i++){
		while (left > qs[i].L){
			left--;
			add(left);
		}
		while (left < qs[i].L){
			sub(left);
			left++;
		}
		while (right < qs[i].R){
			right++;
			add(right);
		}
		while (right > qs[i].R){
			sub(right);
			right--;
		}
		res[qs[i].id] = total;
	}

	for (int i=0; i<m; i++){
		printf("%d\n", res[i]);
	}

	return 0;
}
// 3 1 2 2 3 3 7
// 1 - - - - - 7 (0)
// - - 3 4 - - - (1)
// - - - - 5 6 - (2)
// - - 3 - - 6 - (3)
// 1 - - - 5 - - (4)