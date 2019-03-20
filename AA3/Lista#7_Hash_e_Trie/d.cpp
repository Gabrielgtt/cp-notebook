#include <bits/stdc++.h>
#define MAXN 5000010
#define ll long long
using namespace std;

string word;
string reverseWord;
int dp[MAXN];
int n;
ll reverseHash[MAXN];
ll prime = 70195183;

ll normalHash[MAXN];
ll powers[MAXN];

void buildHash(){
	int base = 503;
	powers[0] = 1;
	for (int i=1; i<MAXN; i++){
		powers[i] = powers[i-1] * base;
		powers[i] %= prime;
	}
	normalHash[0] = word[0] + 293;
	reverseHash[0] = reverseWord[0] + 293;
	for (int i=1; i<n; i++){
		normalHash[i] = (word[i] + 293) + (normalHash[i-1] * base);
		normalHash[i] %= prime;

		reverseHash[i] = (reverseWord[i] + 293) + (reverseHash[i-1] * base);
		reverseHash[i] %= prime;
	}
}

ll subHashInver(int l, int r){
	int aux = r;
	r = n - 1 - l ;
	l = n - 1 - aux;
	return (reverseHash[r] - (reverseHash[l-1] * powers[r-l+1]) % prime + prime) %prime;
}

bool isPal(int index){
	int aux = 0;
	if (!(index & 1)) aux = 1;
	if (index == 0) return true;
	return normalHash[index/2 - aux] == subHashInver(index/2 + 1, index);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> reverseWord;
	n = reverseWord.size();
	word = reverseWord;
	reverse(reverseWord.begin(), reverseWord.end());
	buildHash();

	int res = 0;
	for (int i=0; i<word.size(); i++){
		if (isPal(i)){
			dp[i] = 1 + dp[i/2 - !(i&1)];
			res += dp[i];
		}
	}
	printf("%d\n", res);
	return 0;
}