#include <bits/stdc++.h>

bool jump(int begin, int end, int goal, int i) {
	if (begin == goal) {return true;}
	bool left = false, right = false;
	if (begin - i > 0) {left = jump(begin-i, end, goal, i+2);}
	if (begin + i <= end) {right = jump(begin+i, end, goal, i+2);}
	return left || right;
}

int main(){
	int n, m;
	while (true){
		scanf("%d %d", &n, &m);
		if (n==0 && m==0) {break;}
		if (n > 50 || jump(0, n, m, 1)) {
			printf("Let me try!\n");
		} else {
			printf("Don't make fun of me!\n");
		}
	}
	return 0;
}