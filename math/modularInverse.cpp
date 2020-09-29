int gcd_ex(int a, int b, int& x, int& y) { 
    if (a == 0) { 
        x = 0;
        y = 1;
        return b;
    } 
    int x1, y1;
	int gcd = gcd_ex(b%a, a, x1, y1); 
    x = y1 - (b/a) * x1; 
    y = x1;
    return gcd;
} 

int mod_inv(int a, int m) {
	int x, y;
	gcd_ex(a, m, x, y);
	return (x % m + m) % m;
}
