#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

typedef long long ll;
typedef pair <int, int>  ii;
typedef  pair <int, ii>  iii;


const double EPS = 1e-9;
const double PI = 3.141592653589793;

template <class T>
struct Point{
	T x, y;
	Point() : x(0), y(0) {}
	Point(T _x, T _y) : x(_x), y(_y) {}
	bool operator == (Point <T> p){
		return p.x == this->x && p.y == this->y;
	}
};

template <class T>
struct Vetor {
	T x, y;
	Vetor() : x(0), y(0) {}
	Vetor(T _x, T _y) : x(_x), y(_y) {}
	Vetor(Point <T> a, Point <T> b) : x(b.x - a.x), y(b.y - a.y) {}
};

template <class T>
double dot(Vetor <T> a, Vetor <T> b){
    return (a.x*b.x) + (a.y*b.y);
}
 
template <class T>
double cross(Vetor <T> a, Vetor <T> b){
    return (a.x*b.y) - (a.y*b.x);
}

template <class T>
bool ccw(Point <T> a, Point <T> o, Point <T> b){
	Vetor <T> oa = Vetor <T> (o, a);
	Vetor <T> ob = Vetor <T> (o, b);

	long long res = cross(oa, ob);

	if (res < 0) return false;
	if (res > 0) return true;
	if (res == 0) return true; // Mudar para false se não quiser colinear
}

template <class T>
double angle(Point <T> a, Point <T> o, Point <T> b){
	Vetor <T> oa = Vetor <T> (o, a);
    Vetor <T> ob = Vetor <T> (o, b);
    return acos(dot(oa, ob) / sqrt(dot(oa, oa)*dot(ob, ob)));
}

template <class T>
struct Poly {
	vector <Point <T>> pontos;
	Poly(Point <T>* arrPontos, int size){
		for (int i=0; i<size; i++){
			pontos.emplace_back(arrPontos[i]);
		}
		pontos.emplace_back(arrPontos[0]);
	}
	bool inside(Point <T> p){
		if (pontos.size() == 0) return false;
		double sum = 0;

		for (int i=0; i<pontos.size()-1; i++){
			if (p == pontos[i]) return true;
			if (ccw(pontos[i], p, pontos[i+1])){
				sum += angle(pontos[i], p, pontos[i+1]);
			} else {
				sum -= angle(pontos[i], p, pontos[i+1]);
			}
		}
		return fabs(fabs(sum) - 2*PI) < EPS;
	}
};

Point <double> V[6];

int main(){
	int n, d;
	scanf("%d %d", &n, &d);

	int ps;
	scanf("%d", &ps);
	int x, y;

	V[0] = Point <double> (d, 0);
	V[1] = Point <double> (n, n-d);
	V[2] = Point <double> (n-d, n);
	V[3] = Point <double> (0, d);

	Poly <double> ret = Poly <double> (V, 4);

	for (int i=0; i<ps; i++){
		scanf("%d %d", &x, &y);
		Point <double> p5 = Point <double> (x, y);

		bool res = ret.inside(p5);
		printf("%s\n", (res) ? "YES" : "NO");
	}

	return 0;
}
