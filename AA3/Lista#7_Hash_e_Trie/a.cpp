#include <bits/stdc++.h>
#define MAXN 300010
#define ll long long
using namespace std;

string word[3];

struct HashWord{
	ll powers1[MAXN], hash1[MAXN], primo1;	
	ll powers2[MAXN], hash2[MAXN], primo2;

	HashWord(){};

	HashWord(const string &word){
		ll base1 = 463;
		ll base2 = 541;
		this->primo1 = 70195183;
		this->primo2 = 87889091;

		prePowers(base1, base2, word);
		preHash(base1, base2, word);
	}

	void prePowers(ll base1, ll base2, const string &word){
		powers1[0] = powers2[0] = 1;
		int n = word.size();
		for (int i=1; i<n; i++){
			powers1[i] = (powers1[i-1] * base1) % primo1;
			powers2[i] = (powers2[i-1] * base2) % primo2;
		}
	}

	void preHash(ll base1, ll base2, const string &word){
		hash1[0] = word[0] + 307;
		hash2[0] = word[0] + 307;
		int n = word.size();
		for (int i=1; i<n; i++){
			hash1[i] = ((word[i] + 307) + (hash1[i-1] * base1)) % primo1;
			hash2[i] = ((word[i] + 307) + (hash2[i-1] * base2)) % primo2;
		}		
	}

	pair <ll, ll> interHash(int l, int r){
		if (l == 0) return make_pair(hash1[r], hash2[r]);
		ll ans1 = (hash1[r] - (hash1[l-1] * powers1[r-l+1]) % this->primo1 + this->primo1) % this->primo1;
		ll ans2 = (hash2[r] - (hash2[l-1] * powers2[r-l+1]) % this->primo2 + this->primo2) % this->primo2;
		return make_pair(ans1, ans2);
	}

} hashWord[3];

bool vis[3][3], dpzinha[3][3];

bool inString(int a, int b){
	if (vis[a][b]) return dpzinha[a][b];
	vis[a][b] = true;

	int dif = word[b].size() - word[a].size();

	if (dif < 0) return dpzinha[a][b] = false;
	else if (dif == 0) return dpzinha[a][b] = word[a] == word[b];

	int tam = word[a].size()-1;
	pair <ll, ll> hashzinho = hashWord[a].interHash(0, tam);
	for (int i=0; i<=dif; i++){
		if (hashzinho == hashWord[b].interHash(i, i+tam)){
			return dpzinha[a][b] = true;
		}
	}
	return dpzinha[a][b] = false; 
}

HashWord *hs; 

int solve(int a, int b, int c){
	int res = 0;

	int tam;
	int tam2;
	if (inString(b, a)){
		res = word[a].size();

		if (inString(c, a)){
			return res;
		}

		tam = word[a].size();
		tam2 = word[c].size();
		for (int i=0; i<tam; i++){
			if (hashWord[a].interHash(i, min(tam-1, i+tam2-1)) == hashWord[c].interHash(0, min(tam-1, i+tam2-1)-i)){
				return res + (tam2 - tam + i);
			}
		}
		return res + tam2;
	}

	tam = word[a].size();
	tam2 = word[b].size();
	string newWord = "";
	bool gamb = true;
	for (int i=0; i<tam; i++){
		if (hashWord[a].interHash(i, min(tam-1, i+tam2-1)) == hashWord[b].interHash(0, min(tam-1, i+tam2-1)-i)){
			newWord = word[a] + word[b].substr(tam-i, tam2-tam+i);
			gamb = false;
			break;
		}
	}
	if (gamb) newWord = word[a] + word[b];

	hs = new HashWord(newWord);

	res = tam = newWord.size();
	tam2 = word[c].size();
	for (int i=0; i<tam; i++){
		if (hs->interHash(i, min(tam-1, i+tam2-1)) == hashWord[c].interHash(0, min(tam-1, i+tam2-1)-i)){
			return max(res + (tam2 - tam + i), res);
		}
	}

	return res + tam2;
}

int main(){
	cin >> word[0] >> word[1] >> word[2];

	hashWord[0] = *(new HashWord(word[0]));
	hashWord[1] = *(new HashWord(word[1]));
	hashWord[2] = *(new HashWord(word[2]));

	int res = 1e9;
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			for (int k=0; k<3; k++){
				if (i != j && i != k && j != k){
					res = min(solve(i, j, k), res);
				}
			}
		}
	}

	printf("%d\n", res);
	return 0;
}