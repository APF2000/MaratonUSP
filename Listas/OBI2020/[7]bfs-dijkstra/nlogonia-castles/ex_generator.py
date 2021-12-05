import random
import sys
from math import ceil

def random_conns(n, samples):
	conns = [(i + 2, int( 1 + i * random.random() ) ) for i in range(n - 1)]
	return random.sample(conns, samples)

def rand_tuple_no_rep(n):
	foo = lambda x : int( 1 + x * random.random() )
	num1 = foo(n)
	num2 = foo(n)
	if num1 == num2:
		num2 = (num2 + 1) 
		if num2 == n + 1:
			num2 = 1
	return (num1, num2)

def random_conns_with_rep(n, samples):
	return [rand_tuple_no_rep(n) for i in range(samples)]

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

castle_ends = random_conns_with_rep(n, m)
for color, conn in enumerate(castle_ends):
	print(conn[0], conn[1], color)