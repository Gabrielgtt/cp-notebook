#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int MAXN = 200;
const double EPS = 1e-9;
const double PI = acos(-1);

struct Point{
	int x, y;
	Point(int _x, int _y) : x(_x), y(_y){}	
	Point() : x(0), y(0) {}	
};

Point baseA, baseB;

struct Vetor {
    int x, y;

    Vetor () : x(0), y(0) {}

    Vetor (int _x, int _y) : x(_x), y(_y) {}
};

Vetor toVetor (Point a, Point b){
    return Vetor(b.x-a.x, b.y-a.y);
}

double pe(Vetor a, Vetor b){
    return a.x * b.x + a.y * b.y;
}

double pv(Vetor a, Vetor b){
	return b.y * a.x - a.y * b.x; 
}

double norma(Vetor a){
    return pe(a, a);
}

double angle(Point a, Point o, Point b){
    Vetor oa = toVetor(o, a);
    Vetor ob = toVetor(o, b);

    return acos(pe(oa, ob) / sqrt(norma(oa) * norma(ob)));
}

bool ccw(Point a, Point o, Point c){
	return pv(toVetor(o, a), toVetor(o, c)) > 0;
}

struct Triangle {
	vector <Point> points;

	Triangle () {}

	Triangle(Point a){
		points.push_back(baseA);
		points.push_back(baseB);
		points.push_back(a);
		points.push_back(baseA);
	}

	bool inside(Point p){
		double sum = 0;
		for (int i=0; i < this->points.size()-1; i++){
			if (ccw(p, this->points[i], this->points[i+1])){
				sum += angle(this->points[i], p, this->points[i+1]);
			} else {
				sum -= angle(this->points[i], p, this->points[i+1]); 
			}
		}

		return fabs(fabs(sum) - 2*PI) < EPS;
	}
};

int dp[MAXN];

bool comp(Point a, Point b){
	return a.y < b.y;
}

Point pontos[MAXN];

int main(){
	int n, xa, xb;
	scanf("%d %d %d", &n, &xa, &xb);

	baseA = Point(xa, 0);
	baseB = Point(xb, 0);

	int x, y;
	for (int i=0; i<n; i++){
		scanf("%d %d", &x, &y);
		pontos[i] = Point(x, y);
	}

	sort(pontos, pontos+n, comp);

	int res = 0;
	for (int i=0; i<n; i++){
		Triangle atual = Triangle(pontos[i]);
		dp[i] = 0;
		for (int j=i-1; j>=0; j--){
			if (atual.inside(pontos[j])){
				dp[i] = max(dp[i], dp[j]);
			}
		}
		dp[i]++;
		res = max(res, dp[i]);
	}

	printf("%d\n", res);
	return 0;
}