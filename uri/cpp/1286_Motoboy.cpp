#include <bits/stdc++.h>
#define MAXN 40
using namespace std;

int n, m;

int knapsack[MAXN][MAXN], pizzas[MAXN], tempos[MAXN];
int ks(){
    for (int i=0; i<=n; i++){
        for (int p=0; p<=m; p++){
            if (p==0 || i==0) knapsack[i][p] = 0;
            else if (pizzas[i-1] <= p) knapsack[i][p] = max(knapsack[i-1][p], tempos[i-1] + knapsack[i-1][p - pizzas[i-1]]);
            else knapsack[i][p] = knapsack[i-1][p]; 
        }
    }
    return knapsack[n][m];
}

int main(){

    while(scanf("%d", &n) && n != 0){
        scanf("%d", &m);
        for (int i=0; i<n; i++){
            scanf("%d %d", &tempos[i], &pizzas[i]);
        }
        printf("%d min.\n", ks());
    }   
    
    return 0;
}