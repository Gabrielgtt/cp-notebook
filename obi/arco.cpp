#include <bits/stdc++.h>
#define MAXN 2000020
#define f first
#define ll long long
#define s second
#define ii pair <ll, ll>
using namespace std;

ll pena[MAXN];
ii fle[MAXN];
map <ll, int> bit;
int n;

void update(ll index){
	while (index <= 2000000000000){
		bit[index]++;
		index += index & (-index);
	}
}

ll getSum(ll index){
	ll sum = 0;
	while (index > 0){
		if (bit.count(index)) sum += bit[index];
		index -= index & (-index); 
	}
	return sum;
}

int main(){
	freopen("input", "r", stdin);
	scanf("%d", &n);

	ii p, a;
	ll num;
	ll peso;

	for (int i=1; i<=n; i++){
		scanf("%lld %lld", &a.f, &a.s);

		a.f += pena[i-1];
		a.s += pena[i-1];

		peso = (a.f * a.f) + (a.s * a.s);
		peso++;
		pena[i] = getSum(peso);
		printf("%lld\n", pena[i]);
		update(peso);
	}

	return 0;
}