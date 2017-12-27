#include <bits/stdc++.h>
#define MAXN 1010
#define ii pair <int, int>
#define 
using namespace std;
vector<int> grafo[8];
grafo[0].push_back(1);	grafo[0].push_back(4);
grafo[1].push_back(0);	grafo[1].push_back(2); grafo[1].push_back(5);
grafo[2].push_back(1);	grafo[2].push_back(3); grafo[2].push_back(6);
grafo[3].push_back(2);	grafo[3].push_back(7);
grafo[4].push_back(1);	grafo[4].push_back(5);
grafo[5].push_back(2);	grafo[5].push_back(2); grafo[5].push_back(6);
grafo[6].push_back(3);	grafo[6].push_back(5); grafo[6].push_back(7);
grafo[7].push_back(3);	grafo[7].push_back(6);
int cont2[8];

int djikstra(){
	priority_queue <>
}

int main(){
	memset(desigual, 0, sizeof desigual);
	int cont1[8], num, desigual[8];

	for (int i=0; i<8; i++){
		scanf("%d", &cont1[i]);	
	}

	for (int i=0; i<8; i++){
		scanf("%d", &cont2[i]);	
		desigual[i] = cont1[i] != cont2[i];
	}

	int res = 1e9;
	for (int i=0; i<8; i++){
		if desigual[i]{
			res = min(res, djikstra());
		}
	}



	return 0;
}