#include <bits/stdc++.h>
#define MAXN 230
using namespace std;

struct ponto{
	int x, y;
} pontos[MAXN];

int colinear(struct ponto a, struct ponto b, struct ponto c){
	int y1 = a.y - b.y;
	int y2 = a.y - c.y;
	int x1 = a.x - b.x;
	int x2 = a.x - c.x;
	return (y2 * x1 - y1 * x2) == 0;
}

int main(){
	int n, x, y;
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%d %d", &x, &y);
		pontos[i].x = x;
		pontos[i].y = y;
	}

	int res = 2, temp;
	for (int p1 = 0; p1 < n; p1++){
		for (int p2 = p1+1; p2 < n; p2++){
			temp = 2;
			for (int p3 = 0; p3 < n; p3++){
				if (p3 != p1 && p3 != p2){
					if (colinear(pontos[p1], pontos[p2], pontos[p3])){
						temp++;
					}
				}
			}
			res = max(temp, res);
		}
	}

	printf("%d\n", res);
	return 0;
}