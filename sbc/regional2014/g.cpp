#include <bits/stdc++.h>
#define iii pair< int, pair <int, int> >
#define mp make_pair
#define MAXN 102
using namespace std;

int matriz[MAXN][MAXN][2];
int cam[MAXN][MAXN], proibidas[20];
int n, logi[3000], res;

void bfs(){
	if (proibidas[matriz[0][0][0]] == matriz[0][0][1]) return;
	memset(cam, -1, sizeof cam);
	priority_queue <iii, vector <iii>, greater <iii> > pq;
	pq.push(mp(1, mp(0, 0)));

	int x, y, dist;
	while (!pq.empty()){
		x = pq.top().second.first;
		y = pq.top().second.second;
		dist = pq.top().first;
		pq.pop();

		//direita
		if (x+1 < n && proibidas[matriz[x+1][y][0]] != matriz[x+1][y][1]){
			if (cam[x+1][y] == -1 || dist + 1 < cam[x+1][y]){
				cam[x+1][y] = dist + 1;
				pq.push(mp(cam[x+1][y], mp(x+1, y)));
			}
		}
		//baixo
		if (y+1 < n && proibidas[matriz[x][y+1][0]] != matriz[x][y+1][1]){
			if (cam[x][y+1] == -1 || dist + 1 < cam[x][y+1]){
				cam[x][y+1] = dist + 1;
				pq.push(mp(cam[x][y+1], mp(x, y+1)));
			}
		}
		//esquerda
		if (x-1 >= 0 && proibidas[matriz[x-1][y][0]] != matriz[x-1][y][1]){
			if (cam[x-1][y] == -1 || dist + 1 < cam[x-1][y]){
				cam[x-1][y] = dist + 1;
				pq.push(mp(cam[x-1][y], mp(x-1, y)));
			}
		}
		//cima
		if (y-1 >= 0 && proibidas[matriz[x][y-1][0]] != matriz[x][y-1][1]){
			if (cam[x][y-1] == -1 || dist + 1 < cam[x][y-1]){
				cam[x][y-1] = dist + 1;
				pq.push(mp(cam[x][y-1], mp(x, y-1)));
			}
		}
	}

	if (cam[n-1][n-1] != -1){
		res = min(cam[n-1][n-1], res);
	}
}



int main(){
	char l;
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf(" %c", &l);
			if ((l - 'A') < 26){
				matriz[i][j][0] = l - 'A';
				matriz[i][j][1] = 1;
			} else {
				matriz[i][j][0] = l - 'a';
				matriz[i][j][1] = 0;
			}
		}
	}
	int aux;
	res = 1e9;

	logi[0] = 0;
	logi[1] = 0;
	for (int i=2; i<3000; i++){
		logi[i] = logi[i/2] + 1; 
	}

	for (int i = 0; i <= (1 << 11) - 1; i++){
		aux = i;
		memset(proibidas, 0, sizeof proibidas);
		while (aux > 0){
			proibidas[logi[aux & (-aux)]] = 1;
			aux -= aux & (-aux);
		}
		bfs();
	}

	if (res == 1e9) printf("-1\n");
	else printf("%d\n", res);

	return 0;
}