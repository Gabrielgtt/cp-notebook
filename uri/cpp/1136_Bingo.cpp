#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, b, boo[100], nums[100];
	while (scanf("%d %d", &n, &b) && n != 0){
		memset(boo, 0, sizeof boo);

		for (int i=0; i<b; i++){
			scanf("%d", &nums[i]);
			boo[nums[i]] = 1;
		}

		for (int i=0; i<b-1; i++){
			for (int j=i+1; j<b; j++){
				boo[abs(nums[j]-nums[i])] = 1;
			}
		}

		int flag = 0;
		for (int i=0 ; i<=n; i++){
			if (boo[i] == 0){
				flag = 1;
			}
		}

		if (flag) printf("N\n"); 
		else printf("Y\n");
	}


	return 0;
}