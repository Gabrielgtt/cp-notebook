n, m = map(int, input().split())

media = 0

for i in range(m):
	x, d = map(float, input().split())

	media += x

	if d > 0:
		pa = (((n-1) * n) / 2);
		media += pa * d / n;
	
	elif d < 0:
		if (n & 1):
			aux = (n+1)/2;
			pa = 2 * ((aux-1) * aux / 2);
			media += pa * d / n;
		else:
			aux = (n/2) + 1;
			pa = ((aux-1) * aux / 2) + ((aux-2) * (aux-1) / 2);
			media += pa * d / n;
			
print("%.17f" % media)
	
	
