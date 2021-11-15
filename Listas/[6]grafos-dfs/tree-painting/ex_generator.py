import random
import sys

n = int(sys.argv[1])
print(n)

cons = []
for i in range(2, n + 1):
	aux = [j for j in range(1, i)]# + [j for j in range(i + 1, n)]
	#index = random.randint(1, i - 1) - 1
	#vertex = aux[index]
	vertex = random.sample(aux, 1)[0]
	#cons.append([i, vertex])

	print(i, vertex)
