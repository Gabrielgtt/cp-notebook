a, b, c = map(int, raw_input().split())
h = range(25)
print h[(a + b + c)%24]