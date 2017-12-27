#include <bits/stdc++.h>
#define MAXI 1010
#define MAXT 110
#define rep(i, a, b) for(int (i) = (a); (i)<(b); (i)++)
using namespace std;

double pd[MAXI], compPista, parada[MAXI], carga[MAXI];
int nStops;

double minTemp(){
	double temp;
	pd[0] = 0.0;
	pd[1] = pow(parada[1], 2)/carga[0];

	rep(i, 2, nStops+1){
		rep(j, 0, i){
			temp = pd[j] + pow(parada[i]-parada[j], 2)/carga[j];
			pd[i] = min(pd[i], temp);
		}
	}
	
	return pd[nStops];
}

int main(){
	scanf("%d %lf", &nStops, &compPista);

	rep(i, 0, MAXI){
		pd[i] = 1e8;
	}

	rep(i, 0, nStops){
		scanf("%lf %lf", &parada[i], &carga[i]);
	}
	parada[nStops] = compPista;

	printf("%.3lf\n", minTemp());
	return 0;
}