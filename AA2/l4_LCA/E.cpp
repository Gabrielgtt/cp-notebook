#include <bits/stdc++.h>
#define MAXN 100010
#define LOGMAXN 13
using namespace std;

string presentes[MAXN];
vector <int> grafo[MAXN];
set <string> setzao[MAXN][LOGMAXN];
int parent[MAXN][LOGMAXN];
int flag[MAXN], level[MAXN], pai[MAXN], casas, pergs;

void dfs(int node){
    flag[node] = 1;

    for (int i=0; i<grafo[node].size(); i++){
        int atual = grafo[node][i];
        if (flag[atual] == 0){
            level[atual] = level[node] + 1;
            pai[atual] = node;
            dfs(atual);
        }
    }
}

void construct(){
    for (int i=1; i<=casas; i++){
        setzao[i][0].insert(presentes[i]);
        parent[i][0] = pai[i];
    }

    for (int j=1; j < 14; j++){
        for (int i=1; i<=casas; i++){
            setzao[i][j].insert(setzao[parent[i][j-1]][j-1].begin(), setzao[parent[i][j-1]][j-1].end());
            parent[i][j] = parent[parent[i][j-1]][j-1];
        }
    }
}

// int LCA(){

// }/

int main(){
    cin >> casas >> pergs;

    for (int i=1; i<=casas; i++){
        cin >> presentes[i];
    }

    int de, para;
    for (int i=0; i<casas; i++){
        cin >> de >> para;
        grafo[de].push_back(para);
        grafo[para].push_back(de);
    }

    pai[1] = 1;
    level[1] = 1;
    dfs(1);
    construct();

    return 0;
}
