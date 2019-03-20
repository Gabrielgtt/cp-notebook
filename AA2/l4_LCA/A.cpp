#include <bits/stdc++.h>
#define MAXN 1010
#define LOGMAXN 11
using namespace std;

int t, nodes, pai[MAXN][LOGMAXN], parent[MAXN], level[MAXN];

void preCompute(){
    memset(pai, -1, sizeof pai);

    for (int i = 1; i <= nodes; i++){
        pai[i][0] = parent[i];
    }

    for (int j = 1; (1 << j) < nodes; j++){
        for (int i = 1; i <= nodes; i++){
            if (pai[i][j-1] != -1){
                pai[i][j] = pai[pai[i][j-1]][j-1];
            }
        }
    }
}

int LCA(int u, int v){
    if (level[u] < level[v]) swap(u, v);

    int pulo, dist = level[u] - level[v];

    while (dist > 0) {
        pulo = log2(dist);
        u = pai[u][pulo];
        dist -= (1 << pulo);
    }

    if (u == v) return u;

    for (int j = log2(nodes); j >= 0; j--){
        if ((pai[u][j] != -1 && pai[v][j] != -1) && (pai[u][j] != pai[v][j])){
            u = pai[u][j];
            v = pai[v][j];
        }
    }

    return parent[u];
}

int main(){
    scanf("%d", &t);

    int number, n1, n2, q, aux;

    for (int teste = 1; teste <= t; teste++) {
        scanf("%d", &nodes);
        memset(level, 0, sizeof level);
        memset(parent, 0, sizeof parent);

        for (int i = 1; i <= nodes; i++) {
            scanf("%d", &number);

            if (level[i] == 0) {
                level[i] = 1;
            }
            if (parent[i] == 0){
                parent[i] = i;
            }
            for (int j = 0; j < number; j++) {
                scanf("%d", &aux);
                parent[aux] = i;
                level[aux] = level[i] + 1;
            }
        }

        preCompute();

        scanf("%d", &q);
        printf("Case %d:\n", teste);
        for (int i = 0; i < q; i++) {
            scanf("%d %d", &n1, &n2);
            printf("%d\n", LCA(n1, n2));
        }

    }

    return 0;

}
