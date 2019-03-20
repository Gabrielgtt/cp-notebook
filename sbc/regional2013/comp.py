from os import system
import sys

prob = sys.argv[1]

system("g++ {0}.cpp -Wall -o {0}".format(prob))

if len(sys.argv) == 4:
	system("{0} < {input} > {output}".format(prob, input=sys.argv[2], output=sys.argv[3]))
elif len(sys.argv) == 3:
	system("{0} < {input}".format(prob, input=sys.argv[2]))
else:
	system("{0}".format(prob))