#include <bits/stdc++.h>
using namespace std;

struct Kmp {
	string p, w;
	vector <int> k;

	// Util
	char ch(int i) {
		if (i < p.size()) return p[i];
		if (i == p.size()) return '*';
		return w[i-p.size()-1];
	}

	// O(n) - Build kmp matching p in w
	Kmp(string p_, string w_) : p(p_), w(w_) {
		int ts = p.size() + w.size() + 2;
		k.resize(ts);
		int i = 0, j = -1;
		k[0] = -1;
		while(i < ts){
			while(j >= 0 && ch(i) != ch(j)) j = k[j];
			i++; j++;
			k[i] = j;
		}
	}

	// O(n) - Return all indexes in w where a p match begin
	vector <int> matches() {
		vector <int> res;
		for (int i=0; i<k.size(); i++)
			if (k[i] == p.size()) res.emplace_back(i-1-2*p.size());
		return res;
	}
};

int main() {
	string p = "aba";
	string w = "abakkkkkkkabakkkkkabkkkbakkaba";
	vector <int> kk = Kmp(p, w).matches();
	assert(kk == vector <int> ({0, 10, 27}));
	return 0;
}

