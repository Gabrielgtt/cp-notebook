#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node {
	ll val, l, r;
	node *left, *right;

	node() : left(NULL), right(NULL), val(0) {}

	inline void init(ll a, ll b){
		l = a; 
		r = b;
	}

	inline void extend() {
		if (!left) {
			ll m = l+(r-l)/2;
			left = new node();
			left->init(l, m);
			right = new node();
			right->init(m+1, r);
		}
	}

	ll query(ll de, ll para){
		if (para < l || r < de) return 0;
		if (de <= l && r <= para) return val;
		extend();
		return left->query(de, para) + right->query(de, para);
	}

	void update(ll idx){
		if (l == r){
			val++;
			return;
		}
		extend();
		(idx <= left->r ? left : right)->update(idx);
		val = left->val + right->val;
	}
};

int main(){
	return 0;
}