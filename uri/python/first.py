#include <bits/stdc++.h>
#define tam 1001

using namespace std;

int main(){
	string nome, aux;
	int vet[7];
	int cont;
	printf("         NOME                     CODIGO LOUCO DO ROBERTO\n");
	printf("---------------------------------------------------------\n");
	while(cin >> nome){
		cont = 0;
		aux="";
		memset(vet, 0, sizeof vet);
		for(int i=1;i<nome.size()-1;i++){
			if(nome[i]=='A' || nome[i]=='E' || nome[i]=='I' || nome[i]=='O' || nome[i]=='U' || nome[i]=='Y' || nome[i]=='W' || nome[i]=='H') cont++;
			else if(nome[i]=='B' || nome[i]=='P' || nome[i]=='F' || nome[i]=='V') vet[0] += 1;
			else if(nome[i]=='C' || nome[i]=='S' || nome[i]=='X' || nome[i]=='Z') vet[1] += 1;
			else if(nome[i]=='K' || nome[i]=='G' || nome[i]=='J' || nome[i]=='Q') vet[2] += 1;
			else if(nome[i]=='D' || nome[i]=='T') vet[3] += 1;
			else if(nome[i]=='L') vet[4] += 1;
			else if(nome[i]=='M' || nome[i]=='N') vet[5] += 1;
			else if(nome[i]=='R') vet[6] += 1;			
		}
		aux=nome[0];
		for(int i=0;i<7;i++){
			if(vet[i]>=1){ 
				aux+=(char)(i+1)+48;
				cont+=(vet[i]-1);
			}
		}
		for(int i=0;i<cont;i++){
			aux+="0";
		}
		aux+=nome[nome.size()-1];

		printf("         ");
		cout << nome;
		for (int i=0; i<25-aux.size(); i++) printf(" ");
		cout << aux << endl;

	}
	printf("                   FIM DO PROGRAMA\n");
	return 0;
}

