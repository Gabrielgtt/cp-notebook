#include <bits/stdc++.h>
using namespace std;

typedef double T;

struct pt {
    T x,y;
    pt operator+(pt p) {return {x+p.x, y+p.y};}
    pt operator-(pt p) {return {x-p.x, y-p.y};}
    pt operator*(T d) {return {x*d, y*d};}
    pt operator/(T d) {return {x/d, y/d};} // only for floatingpoint
    T sq(pt p) {return p.x*p.x + p.y*p.y;}
    double abs(pt p) {return sqrt(sq(p));}
};

bool operator==(pt a, pt b) {return a.x == b.x && a.y == b.y;}
bool operator!=(pt a, pt b) {return !(a == b);}

T dot(pt v, pt w) {return v.x*w.x + v.y*w.y;}
bool isPerp(pt v, pt w) {return dot(v,w) == 0;}

T cross(pt v, pt w) {return v.x*w.y - v.y*w.x;}

// a->b->c
// for left turn > 0, right turn < 0, colinear = 0
T orient(pt a, pt b, pt c) {return cross(b-a,c-a);}

double angle(pt v, pt w) {
    double cosTheta = dot(v,w) / abs(v) / abs(w);
    return acos(max(-1.0, min(1.0, cosTheta)));
}

pt rot(pt p, double a) { // Rotation of a point
    return {p.x*cos(a) - p.y*sin(a), p.x*sin(a) + p.y*cos(a)};
}

pt perp(pt p) {return {-p.y, p.x};} // Perpendicular rotation (works for int)

pt scale(pt c, double factor, pt p) { // Scale a point p by a factor from a point C
    return c + (p-c)*factor;
}

template <typename T> int sgn(T x) {
    return (T(0) < x) - (x < T(0));
}

ostream& operator<<(ostream& os, pt p) {
    return os << "("<< p.x << "," << p.y << ")";
}

bool isConvex(vector<pt> p) {
    bool hasPos=false, hasNeg=false;
    for (int i=0, n=p.size(); i<n; i++) {
        int o = orient(p[i], p[(i+1)%n], p[(i+2)%n]);
        if (o > 0) hasPos = true;
        if (o < 0) hasNeg = true;
    }
    return !(hasPos && hasNeg);
}

bool half(pt p) { // true if in blue half
    assert(p.x != 0 || p.y != 0); // the argument of (0,0) is undefined
    return p.y > 0 || (p.y == 0 && p.x < 0);
}
void polarSort(vector<pt> &v) {
    sort(v.begin(), v.end(), [](pt v, pt w) {
            return make_tuple(half(v), 0) <
            make_tuple(half(w), cross(v,w));
            });
}

struct line {
    pt v; T c;
    // From direction vector v and offset c
    line(pt v, T c) : v(v), c(c) {}
    // From equation ax+by=c
    line(T a, T b, T c) : v({b,-a}), c(c) {}
    // From points P and Q
    line(pt p, pt q) : v(q-p), c(cross(v,p)) {}
    // Will be defined later:
    // - these work with T = int
    T side(pt p);
    double dist(pt p);
    line perpThrough(pt p);
    bool cmpProj(pt p, pt q);
    line translate(pt t);
    // - these require T = double
    void shiftLeft(double dist);
    pt proj(pt p);
    pt refl(pt p);
}


int main() {
#ifdef LOCAL
    freopen("input", "r", stdin); 
#endif

    pt a{2, 3}, b{3, 4};

    return 0;
}
