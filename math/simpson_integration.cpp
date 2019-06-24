double simpson_integration(double a, double b, const int N = 1000){
	double h = (b - a) / N;
	double s = f(a) + f(b);
	for (int i = 1; i <= N - 1; ++i) {
		double x = a + h * i;
		s += f(x) * ((i & 1) ? 4 : 2);
	}
	s *= h / 3;
	return s;
}