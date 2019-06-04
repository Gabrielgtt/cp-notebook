int k[MAXN];

void kmp(){
	int i = 0, j = -1;
	k[0] = -1;
	while(i < padrao.size()){
		while(j >= 0 && padrao[i] != padrao[j]) j = k[j];
		i++; j++;
		k[i] = j;
	}
}
