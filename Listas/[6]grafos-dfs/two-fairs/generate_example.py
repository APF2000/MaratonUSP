import sys
from math import sqrt

def print_two_cycles(n):
	m = n + 1
	a = 0
	mid = n // 2
	b = mid

	print(n, m, a, b)
	print(a, b)
	print(a, b - 1)
	print(b, n - 1)

	for i in range(b - 1):
		print(i, i + 1)

	for i in range(b, n - 1):
		print(i, i + 1)

def print_all_connected(n):
	m = (n * (n - 1)) // 2
	a = 0
	b = 1

	print(n, m, a, b)
	for i in range(n):
		for j in range(i + 1, n):
			print(i, j)

n = int(sys.argv[1])
a = 0
b = 1

print(2)
print_two_cycles(n)

n = min(n, 1000)
print_all_connected(n)