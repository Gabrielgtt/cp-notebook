#include <bits/stdc++.h>
#define MAXN 1000010
using namespace std;
	
string lista;

struct dados{
	int esq, dir, dentro;
} st[MAXN*4];

dados dneutro; 

dados query (int node, int start, int end, int left, int right){
	if (right < start || end < left){
		return dneutro;
	}

	if (left <= start && end <= right){
		return st[node];
	}

	int mid = (start+end)/2;

	dados d1 = query(node*2, start, mid, left, right);
	dados d2 = query(node*2+1, mid+1, end, left, right);
	dados res; 
	int mini = min(d1.dir, d2.esq);
	res.dentro = d1.dentro + d2.dentro + mini;
	res.esq = d1.esq + d2.esq - mini;
	res.dir = d1.dir + d2.dir - mini;


	return res;
}

void construct(int node, int start, int end) {
	if (start == end){
		if (lista[start] == '(') st[node].dir++;
		else st[node].esq++;
	} else {
		int mid = (start+end)/2;

		construct(node*2, start, mid);
		construct(node*2+1, mid+1, end);

		int mini = min(st[node*2].dir, st[node*2+1].esq);
		st[node].dentro = st[node*2].dentro + st[node*2+1].dentro + mini;
		st[node].esq = st[node*2].esq + st[node*2+1].esq - mini;
		st[node].dir = st[node*2].dir + st[node*2+1].dir - mini;
	}

}

int main(){
	int q;
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	dneutro.dentro = 0; 
	dneutro.esq = 0; 
	dneutro.dir = 0; 

	cin >> lista;
	cin >> q;	

	construct(1, 0, lista.size()-1);

	int l, r;
	while (q--){
		cin >> l >> r;

		printf("%d\n", query(1, 0, lista.size()-1, l-1, r-1).dentro * 2);
	}
}