#include <bits/stdc++.h>
#define MAXN 100110
using namespace std;

string frase = "";
int back[MAXN];

int main(){
	string pal;
	cin >> pal;
	char pivo = 'a';
	
	if (pal.size() < 26){
		printf("-1\n");
	} else {
		for (int i=0; i<pal.size(); i++){
			if (pal[i] <= pivo){
				pal[i] = pivo;
				pivo++;
				// printf("%c\n", pivo);
			}
			if (pivo == (char) ('z' + 1)){
				break;
			}
		}

		if (pivo != (char) ('z' + 1)){
			printf("-1\n");
		} else {
			cout << pal << endl;
		}
	}

	return 0;
}

// zzzzzzzzzzacbadcbzzzzzzaacceeggiikkmmooqqssuuwwyyzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz
// aacceeggiikkmmooqqssuuwwyyzzzzzzzzzzzzzzzzz