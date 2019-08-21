#include <bits/stdc++.h>
#define ll long long
using namespace std;

const double EPS = 1e-9;
const double PI = 3.141592653589793;

typedef long long T;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

// -----------------------------------------------------------------------------
struct Point {
	T x, y;
	Point(T a=0, T b=0) : x(a), y(b) {}
	bool operator == (const Point& p) const { return p.x == x && p.y == y; }

	bool operator < (const Point& p) const { return x == p.x ? y < p.y : x < p.x; }

	Point operator - (const Point& p) const { return Point(x - p.x, y - p.y); }

	Point vetor(const Point& o) const { return o - (*this); }

	T dot(const Point& b) const { return (x*b.x) + (y*b.y); }

	T cross(const Point& b) const { return (x*b.y) - (y*b.x); }

	// ccw !	
	T cross(const Point& a, const Point& b) const { return (a - *this).cross(b - *this); }
	
	double angle(Point& a, Point& b) const {
		a = vetor(a), b = vetor(b);
		return acos(1.0*a.dot(b) / sqrt(1.0*a.dot(a)*b.dot(b)));
	}
};
// ----------------------------------------------------------------------------- 19928866531

struct Line {
	T A, B, C;

	Line() {}
	Line(const Point& de, const Point& pa) {
		A = de.y - pa.y;
		B = pa.x - de.x;
		C = -A * de.x - B * de.y;
	}
};


// ----------------------------------------------------------------------------- 
struct Seg {
	Point A, B;

	Seg() {}	
	Seg(Point a, Point b) : A(a), B(b) { if (B < A) swap(A, B); }

	T numIntegerPoints() { return gcd(abs(A.x - B.x), abs(A.y - B.y)) + 1LL; }

	bool in(const Point& pt) {
		return min(A.x, B.x) <= pt.x 
			&& pt.x <= max(A.x, B.x) 
			&& min(A.y, B.y) <= pt.y 
			&& pt.y <= max(A.y, B.y) && pt.cross(A, B) == 0;
	}

	bool inter(Seg& o, Point& res){
		Line l1 = Line(A, B), l2 = Line(o.A, o.B);

		T dx = Point(l1.C, l1.B).cross(Point(l2.C, l2.B));
		T dy = Point(l1.A, l1.C).cross(Point(l2.A, l2.C));
		T d = Point(l1.A, l1.B).cross(Point(l2.A, l2.B));

		if (d == 0 || (dx % d != 0) || (dy % d != 0)) return false;
		
		res = Point(-dx / d, -dy / d);
		
		if (!in(res) || !o.in(res)) return false;
		return true;
	}
}; 
// --------------------------------------------------------------------- 20959294248

// --------------------------------------------------------------------- 
struct Poly {
	vector <Point> pts;

	Poly(Point* arrps, int size){
		for (int i=0; i<size; i++){
			pts.emplace_back(arrps[i]);
		}
		pts.emplace_back(arrps[0]);
	}

	vector <Point> convexHull() {
		vector <Point> chain;
		pts.pop_back();
		sort(pts.begin(), pts.end());
			
		for (int i=0; i<pts.size(); i++) {
			while (chain.size() >= 2 && chain[chain.size()-2].cross(chain[chain.size()-1], pts[i]) >= 0) chain.pop_back();
			chain.emplace_back(pts[i]);
		}
		
		int ref = chain.size();
		for (int i=pts.size()-2; i>=0; i--) {
			while (chain.size()-ref >= 1 && chain[chain.size()-2].cross(chain[chain.size()-1], pts[i]) >= 0) chain.pop_back();
			chain.emplace_back(pts[i]);
		}

		pts.emplace_back(pts[0]);
		return chain;
	}

	bool tiraConvexHull() {
		if (pts.size() < 3) return false;
		map <Point, bool> vis;
		vector <Point> hull = convexHull();
		for (Point p : hull) vis[p] = true;
		vector <Point> resto;
		for (Point p : pts) if (!vis[p]) resto.emplace_back(p);
		if (resto.size() > 0) resto.emplace_back(resto[0]);
		pts = resto;
		return true;
	}

	bool inside(Point p){ // TESTAR DEPOIS DE MUDAR ANGLE
		if (pts.size() == 0) return false;
		double sum = 0;
		for (int i=0; i<pts.size()-1; i++){
			if (p == pts[i]) return true;
			if (pts[i].cross(p, pts[i+1])){
				sum += pts[i].angle(p, pts[i+1]);
			} else {
				sum -= pts[i].angle(p, pts[i+1]);
			}
		}
		return fabs(fabs(sum) - 2*PI) < EPS;
	}

	double area(){
		double res = 0.0;
		for (int i=0; i<pts.size()-1; i++){
			res += pts[i].cross(pts[i+1]);
		}
		return fabs(res/2.0);
	}

	bool iConvex(){
		int sz = pts.size();
		if (sz <= 3) return false;
		bool isLeft = pts[0].cross(pts[1], pts[2]);
		for (int i=1; i<sz-1; i++){
			if (pts[i].cross(pts[i+1], pts[(i+2 == sz) ? 1 : i+2]) != isLeft)
				return false;
		}
		return true;
	}
};
// --------------------------------------------------------------------- 54512578721

int main() {
	// TESTES
	
	Point a = Point(0, 0);
	Point b = Point(1, 0);
	Point c = Point(0, 1);
	
	double angulo = a.angle(c, b) * 180.0 / PI;
	assert(angulo == 90.0);
	
	return 0;
}
