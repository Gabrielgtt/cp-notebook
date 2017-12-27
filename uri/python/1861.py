from collections import defaultdict
dic = defaultdict(int)
remove = []

while (1):
	try:
		killer, killed = raw_input().split();
		dic[killer] += 1
		remove.append(killed)
	except EOFError:
		break

for name in remove:
	dic.pop(name, None)

print "HALL OF MURDERERS"

if (len(dic) > 0):
	print "\n".join([ " ".join([key, str(dic[key])]) for key in sorted(dic)])
