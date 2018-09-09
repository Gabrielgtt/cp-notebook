#include <bits/stdc++.h>
#define ii pair <int, int>
#define iii pair <int, ii>
#define mp make_pair
#define LOGMAXN 15
#define MAXN 20000
using namespace std;

vector <iii> edges;
vector <ii> grafo[MAXN];
int parent[MAXN], rank[MAXN], n, m, s;
int pai[MAXN][LOGMAXN], mini[MAXN][LOGMAXN], level[MAXN];
ii acima[MAXN];

void preCompute(){
    memset(pai, -1, sizeof pai);
    for (int i = 1; i <= n; i++){
        pai[i][0] = acima[i].first; // onde eu guardo o vértice exatamente acima na árvore
        mini[i][0] = acima[i].second; // onde eu guardo o custo da aresta pra esse vértice
    }

    for (int j = 1; (1 << j) < n; j++){
        for (int i = 1; i <= n; i++){
            if (pai[i][j-1] != -1){
                pai[i][j] = pai[pai[i][j-1]][j-1];
                mini[i][j] = min(mini[i][j-1], mini[pai[i][j-1]][j-1]);
            }
        }
    }
}

int LCA(int u, int v){
    if (u == v) return 0;

    if (level[u] < level[v]) swap(u, v);

    int pulo, dist = level[u] - level[v], minU = 1e9, minV = 1e9;

    while (dist > 0){
        pulo = log2(dist);
        u = pai[u][pulo];
        minU = min(mini[u][pulo], minU);
        dist -= (1 << pulo);
    }

    if (u == v) minU;

    for (int j = log2(n); j >= 0; j--){
        if ((pai[u][j] != -1 && pai[v][j] != -1) && (pai[u][j] != pai[v][j])){
            u = pai[u][j];
            minU = min(minU, mini[u][j]);
            v = pai[v][j];
            minV = min(minV, mini[v][j]);
        }
    }

    return min(minV, minU);
}

int find(int a){
    if (parent[a] == -1) return a;
    return parent[a] = find(parent[a]);
}

void uni(int a, int b){
    int x = find(a);
    int y = find(b);
    if (rank[x] >= rank[y]){
        rank[x]++;
        parent[b] = parent[a];
    } else {
        rank[y]++;
        parent[a] = parent[b];
    }
}

void mst(){
    sort(edges.begin(), edges.end());
    for (int i=0; i<m; i++){
        iii front = edges[i];
        if (find(front.second.first) != find(front.second.second)){
            uni(front.second.first, front.second.second);
            // grafo[front.second.first].push_back(mp(front.second.second, front.first));
            acima[front.second.second].first = front.second.first;
            acima[front.second.second].second = front.first;
        }
    }
}

int main(){

    while (scanf("%d %d %d", &n, &m, &s) != EOF) {
        memset(parent, -1, sizeof parent);
        memset(rank, 0, sizeof rank);

        int de, para, custo;
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &de, &para, &custo);
            edges.push_back(mp(custo, mp(de ,para)));
        }

        mst();
        preCompute();

        for (int i = 0; i < s; i++){
            scanf("%d %d", &de, &para);
            printf("%d\n", LCA(de, para));
        }

    }
    return 0;
}
