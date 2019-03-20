#include <bits/stdc++.h>
using namespace std;

char grafo[101][101];
bool vis[101][101];
int x, y;

bool out(int a, int b){
	if (0 <= a && a < x && 0 <= b && b < y) return false;
	return true;
}

int main(){
	cin >> x >> y;

	for (int i=0; i<y; i++){
		for (int j=0; j<x; j++){
			cin >> grafo[j][i];
		}
	}

	pair <int, int> dir = make_pair(0, 0); 

	bool flag = false;
	if (grafo[0][0] == '>') dir = make_pair(1, 0), flag = true;
	else if (grafo[0][0] == 'v') dir = make_pair(0, -1), flag = true;

	char res = '!';
	pair <int, int> coor = make_pair(0, 0);
	while (flag){
		
		if (out(coor.first, coor.second)) break;

		char atual = grafo[coor.first][coor.second];

		if (atual == '*'){
			res = '*';
			break;
		}
		if (atual != '.' && vis[coor.first][coor.second]) break;
		if (atual == '>') dir = make_pair(1, 0);
		if (atual == '<') dir = make_pair(-1, 0);
		if (atual == 'v') dir = make_pair(0, 1);
		if (atual == '^') dir = make_pair(0, -1);

		vis[coor.first][coor.second] = true;
		coor.first += dir.first;
		coor.second += dir.second;
	}

	printf("%c\n", res);
	return 0;
}