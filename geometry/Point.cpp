#include <bits/stdc++.h>
#define ll long long
using namespace std;

const double EPS = 1e-9;
const double PI = 3.141592653589793;

struct Point {
	ll x, y;
	Point(ll a=0, ll b=0) : x(a), y(b) {}
	bool operator == (const Point& p) const { return p.x == x && p.y == y; }

	bool operator < (const Point& p) const { return x == p.x ? y < p.y : x < p.x; }

	Point operator - (const Point& p) const { return Point(x - p.x, y - p.y); }

	Point vetor(const Point& o) const { return o - (*this); }

	ll dot(const Point& b) const { return (x*b.x) + (y*b.y); }

	ll cross(const Point& b) const { return (x*b.y) - (y*b.x); }

	// ccw !	
	ll cross(const Point& a, const Point& b) const { return (a - *this).cross(b - *this); }
};

