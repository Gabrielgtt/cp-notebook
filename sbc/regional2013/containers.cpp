#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 340;

int l, n;
int m[MAXN][MAXN];

int arr[MAXN];

int prob(int lim){
    pair<int, int> arrPos[lim];
    for (int i = 0; i < lim; i++){
        arrPos[i].first = arr[i];
        arrPos[i].second = i;
    }
 
    sort(arrPos, arrPos + lim);
 
    vector<bool> vis(lim, false);
 
    int ans = 0;
 
    for (int i = 0; i < lim; i++){
        if (vis[i] || arrPos[i].second == i)
            continue;
 
        int cycle_size = 0;
        int j = i;
        while (!vis[j]){
            vis[j] = 1;
 
            j = arrPos[j].second;
            cycle_size++;
        }
 
        ans += (cycle_size - 1);
    }
 
    return ans;
}

void solve(){
	bool ruim = false;

	for (int i=0; i<l; i++){
		int faixa = -1;		
		for (int j=0; j<n; j++){
			scanf("%d", &m[i][j]);

			if (faixa == -1) {
				faixa = (m[i][j]-1)/n;
			} else {
				if (faixa != (m[i][j]-1)/n){
					ruim = true;
				}
			}
		}
	}

	if (ruim){
		printf("*\n");
		return;
	}

	int res = 0;

	for (int i=0; i<n; i++){
		arr[i] = m[0][i];
	}

	res += prob(n);

	for (int i=0; i<l; i++){
		arr[i] = m[i][0];
	}

	res += prob(l);

	printf("%d\n", res);
}

int main(){

	while (scanf("%d %d", &l, &n) != EOF){
		solve();
	}

	return 0;
}