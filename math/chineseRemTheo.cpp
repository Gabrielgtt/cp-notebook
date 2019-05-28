int gcdExtended(int a, int b, int& x, int& y) { 
	if (a == 0) { 
		x = 0; y = 1; 
		return b; 
	} 
	int x1, y1;
	int gcd = gcdExtended(b%a, a, x1, y1); 
	x = y1 - (b/a) * x1; 
	y = x1; 
	return gcd; 
} 

int modularInverse(int a, int mod) {
	int x, y;
	int g = gcdExtended(a, mod, x, y);
	return (x % mod + mod) % mod;
}

int nums[1000]; // nums são os coprimos
int restos[1000]; // restos são os restos;

int chineseRemTheo() { // use LL provavelmente
	int prod = 1LL;
	for (int i=0; i<3; i++) // n = tamanho do array de coprimos
		prod *= nums[i]; 
	int res = 0;
	for (int i=0; i<3; i++){
		int pp = prod / nums[i];
		res += (((restos[i] * modularInverse(pp, nums[i])) % prod) * pp) % prod;
		res %= prod;
	}
	return res % prod;
}
