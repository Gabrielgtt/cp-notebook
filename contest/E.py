def fatorial(num):
	if num == 0: # Será verificado em cada chamada da função
		return 0 # Só retorna 1
	else:
		return fatorial(num-1) + num

n = int(input())
somaTotal = soma(n)
print(somaTotal)
