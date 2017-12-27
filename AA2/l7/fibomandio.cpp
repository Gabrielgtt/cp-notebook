#include <bits/stdc++.h>
#define MOD 1000000000
#define ll long long int

using namespace std;
ll M[2][2] = {{1,1},{1,0}};

void mult(ll M[2][2], ll P[2][2]){
    ll x = ((((M[0][0] % MOD) * (P[0][0] % MOD)) % MOD) + (((M[0][1] % MOD) * (P[1][0] % MOD)) % MOD)) % MOD;
    ll y = ((((M[0][0] % MOD) * (P[0][1] % MOD)) % MOD) + (((M[0][1] % MOD) * (P[1][1] % MOD)) % MOD)) % MOD;
    ll z = ((((M[1][0] % MOD) * (P[0][0] % MOD)) % MOD) + (((M[1][1] % MOD) * (P[1][0] % MOD)) % MOD)) % MOD;
    ll w = ((((M[1][0] % MOD) * (P[0][1] % MOD)) % MOD) + (((M[1][1] % MOD) * (P[1][1] % MOD)) % MOD)) % MOD;

    M[0][0] = x;
    M[0][1] = y;
    M[1][0] = z;
    M[1][1] = w;
}

void exp(ll M[2][2], ll num){
    if(num == 0 || num == 1) return;

    ll P[2][2] = {{1,1},{1,0}};

    exp(M, num/2);

    mult(M,M);
    if(num%2 != 0) mult(M, P);
}

ll fibo(ll num){
    if(num == 0) return 0;

    exp(M, num-1);
    return M[0][0];
}

int main(){
    ll num;
    scanf("%lld", &num);
    printf("%lld\n", fibo(num));
    return 0;
}