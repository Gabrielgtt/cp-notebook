#include <bits/stdc++.h>
using namespace std;

vector <int> kmp;

// O(n) - Build kmp matching p in w and returns all indexes 
// in w where a p-match begin (requires C++17)
vector <int> matches(string &p, string &w) {
    auto ch = [&](int i) {
        if (i < p.size()) return p[i];
        if (i == p.size()) return '*';
        return w[i-p.size()-1];
    };
    int ts = p.size() + w.size() + 2;
    kmp.resize(ts);
    int i = 0, j = -1;
    kmp[0] = -1;
    while(i < ts){
        while(j >= 0 && ch(i) != ch(j)) j = kmp[j];
        i++; j++;
        kmp[i] = j;
    }
    vector <int> res;
    for (int i=0; i<kmp.size(); i++)
        if (kmp[i] == p.size()) res.emplace_back(i-1-2*p.size());
    return res;
}

int main() {
    string p = "aba";
    string w = "abakkkkkkkabakkkkkabkkkbakkaba";
    vector <int> kk = matches(p, w);
    assert(kk == vector <int> ({0, 10, 27}));
    return 0;
}

