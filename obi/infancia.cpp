#include <bits/stdc++.h>
#define ll long long
#define dd pair <double, double>
#define EPS 1e-9
using namespace std;

struct Ponto{
	ll x, y;

	Ponto() : x(0), y(0) {}

	Ponto(ll _x, ll _y){
		this->x = _x;
		this->y = _y;
	}

	bool operator== (Ponto outro){
		return outro.x == this->x && outro.y == this->y;
	}

	double dist(Ponto outro){
		ll _x = abs(outro.x - this->x) * abs(outro.x - this->x);
		ll _y = abs(outro.y - this->y) * abs(outro.y - this->y);
		return sqrt((double)_x + (double)_y);
	}

	dd medio(Ponto outro){
		return make_pair(fabs(((double)outro.x) + ((double)this->x)) / 2.0,
						 fabs(((double)outro.y) + ((double)this->y)) / 2.0);
	}

} p[9];

struct Vetor {
	ll x, y;
	
	Vetor() : x(0), y(0) {}

	Vetor(ll _x, ll _y) : x(_x), y(_y) {}
};


// produto escalar
ll pe(Vetor a, Vetor b){
    return (a.x*b.x) + (a.y*b.y);
}
 
//produto vetorial
ll pv(Vetor a, Vetor b){
    return (a.x*b.y) - (a.y*b.x);
}

Vetor toVetor(Ponto a, Ponto b){
	return Vetor(a.x - b.x, a.y - b.y);
}

ll ccw(Ponto a, Ponto b, Ponto c){
	Vetor fi = toVetor(a, b);
	Vetor fo = toVetor(a, c);

	ll res = pv(fi, fo);

	if (res < 0) return -1;
	if (res > 0) return 1;
	return 0; 
}

bool c1(){
	return pe(toVetor(p[1], p[2]), toVetor(p[1], p[3])) > 0;
}

bool c2(){
	return fabs(p[1].dist(p[2]) - p[1].dist(p[3])) < EPS;
}

bool c3(){
	return ccw(p[2], p[3], p[4]) == 0 && ccw(p[3], p[4], p[5]) == 0;
}

bool c4(){
	dd m1 = p[2].medio(p[3]);
	dd m2 = p[4].medio(p[5]);

	return  fabs(m1.first - m2.first) < EPS &&
			fabs(m1.second - m2.second) < EPS;
}

bool c5(){
	return p[2].dist(p[3]) > p[4].dist(p[5]);
}

bool c6(){
	Vetor seg1 = toVetor(p[4], p[6]);
	Vetor seg2 = toVetor(p[5], p[7]);
	Vetor seg3 = toVetor(p[2], p[3]);

	return pe(seg1, seg3) == 0 && pe(seg2, seg3) == 0;
}	

bool c7(){
	return fabs(p[4].dist(p[6]) - p[5].dist(p[7])) < EPS;
}

bool c8(){
	return pv(toVetor(p[2],p[3]), toVetor(p[2], p[1])) * pv(toVetor(p[2], p[3]), toVetor(p[2], p[6])) < 0;
}

bool solve(){
	return  c1() &&
			c2() &&
			c3() &&
			c4() &&
			c5() &&
			c6() &&
			c7() &&
			c8();
}

int main(){
	ll x, y;
	for (int i=1; i<=7; i++){
		scanf("%lld %lld", &x, &y);
		p[i] = Ponto(x, y);
	}

	printf("%s\n", solve() ? "S" : "N");

	// printf("%d\n", c1());
	// printf("%d\n", c2());
	// printf("%d\n", c3());
	// printf("%d\n", c4());
	// printf("%d\n", c5());
	// printf("%d\n", c6());
	// printf("%d\n", c7());
	// printf("%d\n", c8());

	return 0;
}