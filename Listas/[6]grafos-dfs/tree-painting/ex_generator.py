import random
import sys

n = int(sys.argv[1])
mode = int(sys.argv[2])

print(n)
if mode == 1:
	ids = [int(i * random.random()) for i in range(n - 1)]

	cons = []
	for i in range(2, n + 1):
		print(i, ids[i - 2])
else:
	for i in range(n - 1):
		print(1, i + 2)