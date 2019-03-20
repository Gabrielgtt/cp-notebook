#include <bits/stdc++.h>
#define MAXN 1010
#define ll long long
#define EPS 1e-9
using namespace std;

double PI = 3.141592653589793;

int s, r, m;

struct Point {
	ll x, y;

	Point(){}

	Point(ll _x, ll _y) {
		this->x = _x;
		this->y = _y;
	}
};
vector <Point> muros[4];


bool ccw(Point p1, Point p2, Point p3){
    ll val = (p2.y - p1.y) * (p3.x - p2.x) -
              (p2.x - p1.x) * (p3.y - p2.y);
 
    if (val == 0) return true;  // colinear
 
    return (val > 0)? false: true; // clock or counterclock wise
}

double angle( Point a, Point b, Point c ){
    Point ab = { b.x - a.x, b.y - a.y };
    Point cb = { b.x - c.x, b.y - c.y };

    double dot = (ab.x * cb.x + ab.y * cb.y); // dot product
    double cross = (ab.x * cb.y - ab.y * cb.x); // cross product

    double alpha = atan2(cross, dot);

    return alpha;
}

int solve(Point p){
	for (int j=0; j<3; j++){
		double sum = 0;

		for (int i=0; i<muros[j].size()-1; i++){
			if (ccw(p, muros[j][i], muros[j][i+1])){
				sum += angle(muros[j][i], p, muros[j][i+1]);
			} else {
				sum -= angle(muros[j][i], p, muros[j][i+1]);
			}
		}

		if (fabs(fabs(sum) - (2 * PI)) < EPS) return j;
	}

	return 3;
}


int main(){
	scanf("%d %d %d", &s, &r, &m);

	Point aux;
	for (int i=0; i<s; i++){
		scanf("%lld %lld", &aux.x, &aux.y);
		muros[0].push_back(aux);
	}
	muros[0].push_back(muros[0][0]);

	for (int i=0; i<r; i++){
		scanf("%lld %lld", &aux.x, &aux.y);
		muros[1].push_back(aux);
	}
	muros[1].push_back(muros[1][0]);

	for (int i=0; i<m; i++){
		scanf("%lld %lld", &aux.x, &aux.y);
		muros[2].push_back(aux);
	}
	muros[2].push_back(muros[2][0]);

	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%lld %lld", &aux.x, &aux.y);

		int res = solve(aux);

		if (res == 0) printf("Sheena\n");
		else if (res == 1) printf("Rose\n");
		else if (res == 2) printf("Maria\n");
		else if (res == 3) printf("Outside\n");
	}

	return 0;
}