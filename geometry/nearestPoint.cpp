#include <bits/stdc++.h>
#define ll long long
using namespace std;

const double EPS = 1e-9;

struct pt {
    ll x, y;

	pt(ll xx = 0, ll yy = 0) : x(xx), y(yy) {}
};

struct cmp_x {
    bool operator()(const pt & a, const pt & b) const {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    }
};

struct cmp_y {
    bool operator()(const pt & a, const pt & b) const {
        return a.y < b.y;
    }
};

double mindist = 1e18; // a menor distancia vai ficar aqui no final

inline void upd_ans(const pt & a, const pt & b) {
	double dist = sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
	if (dist < mindist) {
		mindist = dist;
	}
}

int n;
vector<pt> arr;
vector<pt> temp;

// -----------------------------------------------------------------------------
void rec(ll l, ll r) {
    if (r - l <= 3) {
        for (ll i = l; i < r; ++i) {
            for (ll j = i + 1LL; j < r; ++j) {
                upd_ans(arr[i], arr[j]);
            }
        }
        sort(arr.begin() + l, arr.begin() + r, cmp_y());
        return;
    }

    ll m = (l + r) >> 1LL;
    ll midx = arr[m].x;
    rec(l, m);
    rec(m, r);

    merge(arr.begin() + l, arr.begin() + m, arr.begin() + m, arr.begin() + r, temp.begin(), cmp_y());
    copy(temp.begin(), temp.begin() + r - l, arr.begin() + l);

    ll tsz = 0;
    for (ll i = l; i < r; ++i) {
        if (abs(arr[i].x - midx) < mindist) {
            for (ll j = tsz - 1LL; j >= 0 && arr[i].y - temp[j].y < mindist; --j){
                upd_ans(arr[i], temp[j]);
			}
            temp[tsz++] = arr[i];
        }
    }
}
// ----------------------------------------------------------------------------- 17690314729

int main() {
	for (int i=0; i<4; i++) {
		arr.emplace_back(i, i);
	}
	rec(0, 3);
	assert(fabs(sqrt(2) - mindist) <= EPS);
	printf("%.3f\n", mindist); // ~1.414 (sqrt(2));
	return 0;
}
