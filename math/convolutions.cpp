#include <bits/stdc++.h>
#define ll long long
#define LOGN 20
#define MAXN (1 << LOGN)
using namespace std;

// Fazendo C[i] = sum (A[j] * B[i^j]) (para todo j subset de i)
 
// Perceba que se o j não precisasse ser subset de i, ficaria mais fácil (era exatamente o "FFT de xor")
 
 
// =====================================================================
 
// *** Fazendo em 3^N ***
 
vector<ll> other_convolution(vector<ll> a) {
    vector<ll> ret(MAXN);
    for(int mask = 0; mask < MAXN; mask++)
        for(int subset = mask;; subset = (subset-1) & mask) {
            ret[mask] = (ret[mask] + a[subset]*a[mask^subset]) % MOD;
            if(!subset) break;
        }
    return ret;
}
 
// =====================================================================
 
// *** Fazendo em 2^N * N^2 ***
// https://c...content-available-to-author-only...s.com/blog/entry/57250?#comment-409117
 
// Meu código:
 
// ------------------------------------------------------------------------------ 
vector<ll> SSC(vector<ll> &a, vector<ll> &b) {
    vector<ll> fa[LOGN+1], fb[LOGN+1], fc[LOGN+1], ret(MAXN);
 
    for(int i = 0; i <= LOGN; i++) {
        fa[i].resize(MAXN);
        fb[i].resize(MAXN);
        fc[i].resize(MAXN);
    }
 
    for(int i = 0; i < MAXN; i++) {
        fa[__builtin_popcount(i)][i] = a[i];
        fb[__builtin_popcount(i)][i] = b[i];
    }
 
    for(int i = 0; i <= LOGN; i++) {
        FST(fa[i]);
        FST(fb[i]);
    }
 
    for(int i = 0; i < MAXN; i++)
        for(int b = 0; b <= LOGN; b++)
            for(int j = 0; j <= b; j++)
                fc[b][i] += fa[j][i] * fb[b-j][i];
 
    for(int i = 0; i <= LOGN; i++)
        FST(fc[i], true);
 
    for(int i = 0; i < MAXN; i++)
        ret[i] = fc[__builtin_popcount(i)][i];
 
    return ret;
}
// ------------------------------------------------------------------------------ 18422716226

// ** FST / SOS DP **
 
// ------------------------------------------------------------------------------ 
void FST(vector<ll> &a, bool inverse = false) {
    for (int b = 0; b < LOGN; b++)
        for (int i = 0; i < MAXN; i++)
            if ((i & (1 << b)) == 0)
                a[i + (1 << b)] += a[i] * (inverse ? -1 : 1);
}
// ------------------------------------------------------------------------------ 4328704132


// ===============================================================
 
// ** Fast Walsh-Hadamard Transform **
/// in convolution op is 0 for XOR, 1 for AND, 2 for OR
 
// ------------------------------------------------------------------------------ 
int T[3][2][2][2] = {
    { { {1,  1}, {1, -1} }, { {1,  1}, {1, -1} } }, /// xor
    { { {0,  1}, {1,  1} }, { {-1, 1}, {1,  0} } }, /// and
    { { {1,  1}, {1,  0} }, { {0,  1}, {1, -1} } }  /// or
};
 
void FFT(vector<ll> &a, int op, bool inverse = false) {
    int u1 = T[op][inverse][0][0], v1 = T[op][inverse][0][1];
    int u2 = T[op][inverse][1][0], v2 = T[op][inverse][1][1];
 
    for(int b = 0; b < LOGN; b++)
        for(int i = 0; i < MAXN; i++)
            if((i & (1 << b)) == 0) {
                ll u = a[i], v   = a[i + (1 << b)];
                a[i]            = u*u1 + v*v1;
                a[i + (1 << b)] = u*u2 + v*v2;
            }
 
    if (op == 0 && inverse)
        for (int i=0; i<a.size(); i++)
            a[i] >>= LOGN;
}
 
vector<ll> convolution(vector<ll> a, vector<ll> b, int op) {
    FFT(a, op, false);
    FFT(b, op, false);
    for(int i=0; i<a.size(); i++)
        a[i] = a[i] * b[i];
    FFT(a, op, true);
    return a;
}
// ------------------------------------------------------------------------------ 21212486588
