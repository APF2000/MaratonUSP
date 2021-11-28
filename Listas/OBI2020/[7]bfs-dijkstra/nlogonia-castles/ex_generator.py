import random
import sys

def random_conns(n, samples):
	conns = [(i + 2, int( 1 + i * random.random() ) ) for i in range(n - 1)]
	return random.sample(conns, samples)

n = int(sys.argv[1])
m = int(sys.argv[2])
mode = int(sys.argv[3])

print(n, m)

# random tree
if mode == 1: 
	conns = random_conns(n, n - 1)
	for conn in conns:
		print(conn[0], conn[1])
		
# star tree
else:
	for i in range(n - 1):
		print(1, i + 2)

castle_ends = random_conns(n, m)
for color, conn in enumerate(castle_ends):
	print(conn[0], conn[1], color)