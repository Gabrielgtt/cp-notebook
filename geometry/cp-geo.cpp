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

void convex_hull(vector<pt>& a) {
    if (a.size() == 1) return;
    sort(a.begin(), a.end(), [&](pt a, pt b) { 
        return a.x < b.x || (a.x == b.x && a.y < b.y); 
    });
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || orient(p1, a[i], p2) < 0) {
            while (up.size() >= 2 && orient(up[up.size()-2], up[up.size()-1], a[i]) >= 0)
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || orient(p1, a[i], p2) > 0) {
            while(down.size() >= 2 && orient(down[down.size()-2], down[down.size()-1], a[i]) <= 0)
                down.pop_back();
            down.push_back(a[i]);
        }
    }
    a.clear();
    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);
}

bool above(pt a, pt p) { return p.y >= a.y; }

bool crossesRay(pt a, pt p, pt q) {
    return (above(a,q) - above(a,p)) * orient(a,p,q) > 0;
}

bool inDisk(pt a, pt b, pt p) { return dot(a-p, b-p) <= 0; }

bool onSegment(pt a, pt b, pt p) {
    return orient(a,b,p) == 0 && inDisk(a,b,p);
}

bool inPolygon(vector<pt> p, pt a, bool strict = true) {
    61
    int numCrossings = 0;
    for (int i = 0, n = p.size(); i < n; i++) {
        if (onSegment(p[i], p[(i+1)%n], a))
            return !strict;
            numCrossings += crossesRay(a, p[i], p[(i+1)%n]);
    }
    return numCrossings & 1; // inside if odd number of crossings
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin); 
#endif

    pt a{2, 3}, b{3, 4};

    return 0;
}
