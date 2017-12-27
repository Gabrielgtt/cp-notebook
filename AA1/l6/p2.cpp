#include <bits/stdc++.h>
#define mk(a, b, c) make_pair(a, make_pair(b, c))
#define ii pair <int, int>
#define iii pair <int, pair <int, int> >
#define second second.first
#define third second.second
using namespace std;

int matriz[101][101], totalDoente;
int p1 = {1, 1, 1, 0, 0, -1, -1, -1};
int p2 = {0, 1, -1, 1, -1, 0, 1, -1};

void bfs(int x, int y) {
    queue < iii > fila;
    bool vis[110];
    fila.push(mk(x, y, 1));

    while (!fila.empty()) {
        iii atual = fila.top(); fila.pop();

        for (int i = 0; i < 8; i++) {

        }
    }
}

int main(){
    int t;
    while (t--){
        scanf("%d %d", &m, &n);
        totalDoente = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++){
                scanf("%d", matriz[i][j]);
                if (matriz[i][j] == 1) totalDoente++;
            }
        }

        int coorx, coory;
        scanf("%d %d", &coorx, &coory);

        bfs(--coorx, --coory);
    }

    return 0;
}
