#include <bits/stdc++.h>
#define inf 1e9

using namespace std;
int verts, dist[501][501];
typedef pair<int, int> ii;

void djikstra(vector<pair<int, int> > grafo[], int start) {
	int custo, cidade, city, cust;

	priority_queue<ii, vector<ii>, greater<ii> > PQ;
	PQ.push(make_pair(0, start));
	dist[start][start] = 0;

	while (!PQ.empty()){
		custo = PQ.top().first;
		cidade = PQ.top().second;
		PQ.pop();

		for (int i=0; i<grafo[cidade].size(); i++){
			city = grafo[cidade][i].second;
			cust = grafo[cidade][i].first;
			if (dist[start][city] > cust + custo) {
				dist[start][city] = cust + custo;
				PQ.push(make_pair(dist[start][city], city));
			}
		}
	}

	for (int i=0; i<verts; i++){
		if (dist[start][i] == 1e9){
			dist[start][i] = -1;
		}
	}
}



int main(){
	int edges, de, para, custo;

	while (scanf("%d %d", &verts, &edges)){
		if (!verts and !edges) break;
		verts++;
		for (int i=0; i<verts; i++){
			for (int k=0; k<verts; k++){
				dist[i][k] = inf;
			}
		} 

		vector<pair<int, int> > grafo[verts];

		for (int i=0; i<edges; i++){
			scanf("%d %d %d", &de, &para, &custo);

			for (int k=0; k<grafo[para].size(); k++){
				if (grafo[para][k].second == de) {
					grafo[para][k].first = 0;
					custo = 0;
				}
			}
			grafo[de].push_back(make_pair(custo, para));
		}

		int k; scanf("%d", &k);
		for (int i=0; i<k; i++){
			scanf("%d %d", &de, &para);
			if (dist[de][para] == 1e9) djikstra(grafo, de);

			if (dist[de][para] == -1){ printf("Nao e possivel entregar a carta\n");
			} else {
				printf("%d\n", dist[de][para]);
			}
		}

		printf("\n");

		for (int i=0; i<verts; i++){
			for (int k=0; k<verts; k++){
				dist[i][k] = inf;
			}
		} 
	}

	return 0;
}