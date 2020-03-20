#include <bits/stdc++.h>
#define MAXN 1000100
using namespace std;
vector <int> grafo[MAXN], grafot[MAXN];

int order[MAXN], comp[MAXN];
bool ass[MAXN], used[MAXN];

void dfs1(int v, int &id) {
	used[v] = true;
	for (int u : grafo[v]) 
		if (!used[u]) dfs1(u, id);
	order[id++] = v;
}

void dfs2(int v, int cl) {
	comp[v] = cl;
	for (int u : grafot[v])
		if (comp[u] == -1) dfs2(u, cl);
}

// para a variavel k: k*2 = true, k*2+1 = false
bool solve_2SAT(int N) {
	for (int i=0; i<N; i++) comp[i] = -1, used[i] = false, ass[i] = false;
	for (int i=0; i<MAXN; i++) for (int u : grafo[i]) grafot[u].emplace_back(i);
	int id = 0;
	for (int i = 0; i < N; ++i) 
		if (!used[i]) dfs1(i, id);
	for (int i = 0, j = 0; i < N; ++i) {
		int v = order[N - i - 1];
		if (comp[v] == -1)
			dfs2(v, j++);
	}
	for (int i = 0; i < N; i += 2) {
		if (comp[i] == comp[i + 1]) return false;
		ass[i / 2] = comp[i] > comp[i + 1];
	}
	return true;
}

int main() {
	return 0;
}

