import random
import sys

n = int(sys.argv[1])
print(n)

ids = [int(i * random.random()) for i in range(n - 1)]

cons = []
for i in range(2, n + 1):
	print(i, ids[i - 2])
