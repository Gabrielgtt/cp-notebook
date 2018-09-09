#include <bits/stdc++.h>
#define MAXN 3000000
#define debug_arr(arr, tam) cerr << #arr << " = "; for (int i=0; i<tam; i++) printf("%d%c", arr[i], " \n"[i == tam-1]);
using namespace std;

int n, m;
int walls[MAXN];
int bears[MAXN], ele[MAXN];
int back[MAXN];

int main(){
	scanf("%d %d", &n, &m);

	for (int i=0; i<n; i++){
		scanf("%d", &bears[i]);
		if (i > 0) walls[m+i-1] = bears[i] - bears[i-1];
	}

	walls[m-1] = 1e9+7;

	for (int i=0; i<m; i++){
		scanf("%d", &ele[i]);
		if (i > 0) walls[i-1] = ele[i] - ele[i-1];
	}

	if (m == 1){
		printf("%d\n", n);
		return 0;
	}

	int res = 0;
	for (int i=1, j; i<n+m-1; i++){
		j = back[i-1];
		while (j > 0 && walls[i] != walls[j]) j = back[j-1];
		if (walls[i] == walls[j]) j++;
		back[i] = j;
		if (j == m-1) res++;
	}

	printf("%d\n", res);
	return 0;
}