#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
const double PI = 3.141592653589793;

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

