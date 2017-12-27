#include <bits/stdc++.h>
using namespace std;

struct event {
	int freq, tipo, id;

	event() {}
	event(int a, int b, int c) : freq(a), tipo(b), id(c) {}

	bool operator < (const event &o) const {
		if (freq == o.freq){
			if (tipo == o.tipo) return id < o.id;
			return tipo < o.tipo;
		}
		return freq < o.freq;
	}
};

int main(){
	int n, i, res, len, A, B;

	while (scanf("%d", &n) != EOF){
		len = n << 1;
		vector <event> tempo; tempo.reserve(len);
		event temp;
		res = 0;

		for (i=0; i<n; i++){
			scanf("%d %d", &A, &B);
			temp.freq = A; temp.tipo = 0; temp.id = i;
			tempo.push_back(temp);
			temp.freq = B; temp.tipo = 1; temp.id = i;
			tempo.push_back(temp);
		}

		sort(tempo.begin(), tempo.end());

		set <int> open;
		vector <event>::iterator ev;

		for (ev = tempo.begin(); ev != tempo.end(); ev++){
			if (ev->tipo == 1 && open.count(ev->id)){
				res++;
				open.clear();
			} else {
				open.insert(ev->id);
			}
		}

		printf("%d\n", res);
	}

	return 0;
}