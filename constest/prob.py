a, b = raw_input().split()

ans1 = a[0]

i = 1
while (i < len(a) and b[0] > a[i]):
	ans1 += a[i]
	i += 1
ans1 += b[0]

print ans1