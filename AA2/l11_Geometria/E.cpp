#include <bits/stdc++.h>
#define MAXN 10020
using namespace std;

struct ponto{
	int x, y;
} pontos[MAXN];

int n, armaX, armaY;
bool colinear(struct ponto p2, struct ponto p3){
	int y1 = armaY - p2.y;
	int y2 = armaY - p3.y;
	int x1 = armaX - p2.x;
	int x2 = armaX - p3.x;
	return (y2 * x1 - y1 * x2) == 0;
}

int main(){
	scanf("%d %d %d", &n, &armaX, &armaY);
	int x, y;
	for (int i=0; i<n; i++){
		scanf("%d %d", &x, &y);
		pontos[i].x = x;
		pontos[i].y = y;
	}

	vector<struct ponto> retas;
	int res = 0;
	bool taNaReta;
	for (int p1 = 0; p1 < n; p1++){
		taNaReta = false;
		for (int r = 0; r < retas.size(); r++){
			if (colinear(retas[r], pontos[p1])){
				taNaReta = true;
				break;
			}
		}
		if (!taNaReta){
			retas.emplace_back(pontos[p1]);
			res++;
		}
	}

	printf("%d\n", res);
	return 0;
}