#include <bits/stdc++.h>
#define mp make_pair
#define MAXN 200010
#define MAXLOG 22
#define ii pair <int, int>
#define ll long long
#define pb push_back
using namespace std;

int arr[MAXN*2], beg[MAXN], fin[MAXN], luz[MAXN], index = 0, seg[MAXN*8][2], lazy[MAXN*8];
bool vis[MAXN];
vector <int> grafo[MAXN];

void dfs(int node){
	vis[node] = true;
	beg[node] = index;
	arr[index++] = luz[node];
	for (int i=0; i<grafo[node].size(); i++){
		int prox = grafo[node][i];
		if (!vis[prox]){
			dfs(prox);
		}
	}
	fin[node] = index;
	arr[index++] = luz[node];
}

void doLazy(int node, int start, int end){
	swap(seg[node][0], seg[node][1]);
	if (start != end){
		lazy[node*2] ^= 1;
		lazy[node*2+1] ^= 1;
	}
	lazy[node] = 0;
}

void update(int node, int start, int end, int left, int right){
	if (lazy[node]) doLazy(node, start, end);

	if (right < start || end < left) return;

	if (left <= start && end <= right){
		doLazy(node, start, end);
	} else {
		int mid = (start+end)>>1;
		update(node*2, start, mid, left, right);
		update(node*2+1, mid+1, end, left, right);
		seg[node][0] = seg[node*2][0] + seg[node*2+1][0];
		seg[node][1] = seg[node*2][1] + seg[node*2+1][1];
	}
}

int query(int node, int start, int end, int left, int right){
	if (lazy[node]) doLazy(node, start, end);

	if (right < start || end < left) return 0;

	if (left <= start && end <= right){
		return seg[node][1];	
	} 

	int mid = (start+end)>>1;

	return query(node*2, start, mid, left, right) + query(node*2+1, mid+1, end, left, right);
}

void buildTree(int node, int left, int right){
	if (left == right){
		if (arr[left] == 1){
			seg[node][1]++;
		} else {
			seg[node][0]++;
		}
	} else {
		int mid = (left+right)>>1;
		buildTree(node*2, left, mid);
		buildTree(node*2+1, mid+1, right);
		seg[node][0] = seg[node*2][0] + seg[node*2+1][0];
		seg[node][1] = seg[node*2][1] + seg[node*2+1][1];
	}
}

int main(){
	ios::sync_with_stdio(false);
	int n, pai;
	cin >> n;
	for (int i=2; i<=n; i++){
		cin >> pai;
		grafo[pai].pb(i);
	}
	for (int i=1; i<=n; i++){
		cin >> luz[i];
	}

	dfs(1);
	buildTree(1, 0, (n*2)-1);

	int q, v;
	string tipo;
	cin >> q;

	for (int i=0; i<q; i++){
		cin >> tipo >> v;
		if (tipo == "get"){
			printf("%d\n", query(1, 0, (n*2)-1, beg[v], fin[v]) >> 1);
		} else {
			update(1, 0, (n*2)-1, beg[v], fin[v]);
		}
	}
	return 0;
}