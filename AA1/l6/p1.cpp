#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;

int binarySearch(int left, int right, int value){
    if (left == right) return array[left]; // ou right
    int mid = (left+right)/2;

    if (value < array[mid]) return binarySearch(left, mid, value);
    return binarySearch(mid+1, right, value);
}


int main(){
    int n, tipo, m, a, b;

    while (scanf("%d %d", &n, &m) != EOF) {
        memset(flags, 0, sizeof flags);
        for (auto& v : grafo){
            v.clear();
        }
        res = 0;
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            grafo[a].push_back(b);
            grafo[b].push_back(a);
        }

        scanf("%d", &tipo);

        dfs(tipo);
        printf("%d\n", res);
    }

    return 0;
}
