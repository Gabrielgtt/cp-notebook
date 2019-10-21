#include <bits/stdc++.h>
#define MAXN 1000010
using namespace std;

const int K = 26;
int dp[MAXN];

struct node {
    int next[K];
    int go[K];
    bool leaf = false;
    int p = -1;
    char pch;
    int link = -1;

    node(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector <node> aho(1);
int go(int v, char ch);
int get_link(int v) {
    if (aho[v].link == -1) {
        if (v == 0 || aho[v].p == 0) aho[v].link = 0;
        else aho[v].link = go(get_link(aho[v].p), aho[v].pch);
    }
    return aho[v].link;
}

int go(int v, char ch) {
    int c = ch - 'a';
    if (aho[v].go[c] == -1) {
        if (aho[v].next[c] != -1) aho[v].go[c] = aho[v].next[c];
        else aho[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return aho[v].go[c];
} 

void read_string() {
    int v = 0; char ch;
    while (true) {
		scanf("%c", &ch);
		if (ch < 'a' || ch > 'z') break;
		int c = ch - 'a';
        if (aho[v].next[c] == -1) {
            aho[v].next[c] = aho.size();
            aho.emplace_back(v, ch);
        }
        v = aho[v].next[c];
    }
    aho[v].leaf = true;
}

int res = 0;

void solve(int v) {
	queue <int> qu;
	qu.push(v);

	while(!qu.empty()) {
		int atual = qu.front();
		qu.pop();
		int pai = aho[atual].p;
		if (pai == -1) pai = 0;
		dp[atual] = max(dp[get_link(atual)], dp[pai]) + aho[atual].leaf;
		res = max(dp[atual], res);

		for (int l = 0; l < K; l++) {
			if (aho[atual].next[l] != -1) qu.push(aho[atual].next[l]);
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("input", "r", stdin);
#endif

	int n;
	while (1) {
		scanf("%d", &n); getchar();
		if (!n) break;
		for (int i=0; i<=aho.size(); i++) dp[i] = 0;
		aho.clear();
		aho.emplace_back(node());
		for (int i=0; i<n; i++) {
			read_string();			
		}
		res = 0;
		solve(0);
		printf("%d\n", res);
	}

	return 0;
}

