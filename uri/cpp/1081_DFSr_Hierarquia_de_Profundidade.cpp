#include <bits/stdc++.h>
using namespace std;


!!!!!!!!!!! RODE PRA ACHAR OS ERROS !!!!!!!!!!!!!!!!!

void dfs(vector<vector<int> > graph, int start, set<int> flags, string espaco){
	flags.insert(start);
	for (int i=0; i<graph[start].size; i++){
		if (const bool flags.find(graph[start][i]) != flags.end()){
			printf("%s%d-%d\n", espaco, start, graph[start][i]);
		} else {
		flags.insert(graph[start][i]);
		printf("%s%d-%d pathR(G, %d)\n", espaco, start, graph[start][i], graph[start][i]);
		if (const bool graph.find(graph[start][i]) != graph.end()){
			dfs(graph, graph[start][i], flags, espaco.append(" "))
		}
		}
	}
}
	
int main(){
	int num_vert, num_edges, x, from, to;
	scanf("%d", &x);
	
	for (int n=0; n<x; n++){

		scanf("%d %d", &num_vert, &num_edges);
		vector< vector<int> > mapa(num_vert, vector<int>());
		set<int> flags;

		for (int i=0; i<num_vert; i++){
			mapa.push_back(vector<int>());
		}
		for (int i=0; i<num_edges; i++){
			scanf("%d %d", &from, &to);
			mapa[from].push_back(to);
		}

		printf("Caso %d:\n", n+1);
		for (int key=0; key<mapa.size(); key++){
			if (!flags.find(key)){
				dfs(mapa, key, flags, " ")
			}
		}

		// cout << "Mapa:" << endl;
		// for (int i=0; i<num_vert; i++){
		// 	printf("Linha %d: ", i);
		// 	for(int x=0; x<mapa[i].size(); x++){
		// 		printf("%d ", mapa[i][x]);
		// 	}
		// 	cout << endl;
		// }

	}
	return 0;
}