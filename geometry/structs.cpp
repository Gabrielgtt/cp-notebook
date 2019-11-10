#include <bits/stdc++.h>
#define ll long long
using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1);

typedef long long T;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

struct Pt {
	T x, y;

	Pt(T a=0, T b=0) : x(a), y(b) {}

	bool operator == (const Pt& p) const { return p.x == x && p.y == y; }

	bool operator < (const Pt& p) const { return x == p.x ? y < p.y : x < p.x; }

	Pt operator - (const Pt& p) const { return {x - p.x, y - p.y}; }
	
	Pt operator + (const Pt& p) const { return {x + p.x, y + p.y}; }
	
	Pt operator / (const T c) const { return {x / c, y / c}; }
	
	Pt operator * (const T c) const { return {x * c, y * c}; }

	Pt vetor(const Pt& p) const { return p - (*this); }

	T dot(const Pt& b) const { return (x*b.x) + (y*b.y); }
	
	T sq() const { return (x*x) + (y*y); }

	double dist(const Pt& b) { return sqrt((b - *this).sq()); }

	T cross(const Pt& b) const { return (x*b.y) - (y*b.x); }

	/*
		CCW do vetor (this -> a) em relação ao ponto b
		0, b for colienar ao vetor (this -> a) 
		Negativo ou positivo dependendo do lado que b está do vetor
	*/
	T cross(const Pt& a, const Pt& b) const { return (a - *this).cross(b - *this); }
	
	double angle(Pt a, Pt b) const {
		Pt va = a - (*this);
		Pt vb = b - (*this);
		return acos(1.0 * va.dot(vb) / sqrt(1.0 * va.dot(va) * vb.dot(vb)));
	}
};

Pt perp(Pt p) { return {-p.y, p.x}; }

Pt circumCenter(Pt a, Pt b, Pt c) {
	b = b-a, c = c-a;
	return a + (perp(b*c.sq() - c*b.sq()) / b.cross(c)) / 2;
}

ostream& operator<< (ostream& os, Pt p) {
	return os << "("<< p.x << "," << p.y << ")";
}

template <typename F> int sgn(F x) {
	return (F(0) < x) - (x < F(0));
}

struct Line {
	T A, B, C;

	Line() {}
	Line(const Pt& de, const Pt& pa) {
		A = de.y - pa.y;
		B = pa.x - de.x;
		C = -A * de.x - B * de.y;
	}
};

/*
	Comparador de maior ou igual para double
*/
bool mORe(double a, double b) {
	return a <= b || fabs(a - b) <= EPS;
}

// ----------------------------------------------------------------------------- 
struct Seg {
	Pt A, B;

	Seg() {}	
	Seg(Pt a, Pt b) : A(a), B(b) { if (B < A) swap(A, B); }

	T numIntegerPoints() { return gcd(abs(A.x - B.x), abs(A.y - B.y)) + 1LL; }

	bool inDouble(const Pt& Pt) {
		return mORe(min(A.x, B.x), Pt.x) 
			&& mORe(Pt.x, max(A.x, B.x)) 
			&& mORe(min(A.y, B.y), Pt.y)
			&& mORe(Pt.y, max(A.y, B.y));
	}

	bool in(const Pt& Pt) {
		return min(A.x, B.x) <= Pt.x 
			&& Pt.x <= max(A.x, B.x) 
			&& min(A.y, B.y) <= Pt.y 
			&& Pt.y <= max(A.y, B.y);
	}

	bool inter(Seg& o, Pt& res){
		Line l1 = Line(A, B), l2 = Line(o.A, o.B);

		T dx = Pt(l1.C, l1.B).cross(Pt(l2.C, l2.B));
		T dy = Pt(l1.A, l1.C).cross(Pt(l2.A, l2.C));
		T d = Pt(l1.A, l1.B).cross(Pt(l2.A, l2.B));

		if (d == 0 || (dx % d != 0) || (dy % d != 0)) return false;
		
		res = Pt(-dx / d, -dy / d);
		
		if (!in(res) || !o.in(res)) return false; // trocar para inDouble se estiver usando Double
		return true;
	}
}; 
// --------------------------------------------------------------------- 

// --------------------------------------------------------------------- 
struct Poly {
	vector <Pt> pts;

	Poly(Pt* arrps, int size){
		for (int i=0; i<size; i++){
			pts.emplace_back(arrps[i]);
		}
		pts.emplace_back(arrps[0]);
	}

	vector <Pt> convexHull() {
		vector <Pt> chain;
		pts.pop_back();
		sort(pts.begin(), pts.end());
			
		int sz = 0;
		for (int i=0; i<pts.size(); i++) {
			while (sz >= 2 && chain[sz-2].cross(chain[sz-1], pts[i]) >= 0) chain.pop_back(), sz--;
			chain.emplace_back(pts[i]);
			sz++;
		}
		
		int ref = sz;
		for (int i=pts.size()-2; i>=0; i--) {
			while (sz-ref >= 1 && chain[sz-2].cross(chain[sz-1], pts[i]) >= 0) chain.pop_back(), sz--;
			chain.emplace_back(pts[i]);
			sz++;
		}

		pts.emplace_back(pts[0]);
		return chain;
	}

	bool tiraConvexHull() {
		if (pts.size() < 3) return false;
		map <Pt, bool> vis;
		vector <Pt> hull = convexHull();
		for (Pt p : hull) vis[p] = true;
		vector <Pt> resto;
		for (Pt p : pts) if (!vis[p]) resto.emplace_back(p);
		if (resto.size() > 0) resto.emplace_back(resto[0]);
		pts = resto;
		return true;
	}

	bool inside(Pt p){ // TESTAR DEPOIS DE MUDAR ANGLE
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
// ---------------------------------------------------------------------

int main() {
	// TESTES
	Pt a{0, 0}, b{1, 0}, c{0, 1};
	double angulo = a.angle(c, b) * 180.0 / PI;
	assert(angulo == 90.0);
	cout << a - b << endl;
	return 0;
}
