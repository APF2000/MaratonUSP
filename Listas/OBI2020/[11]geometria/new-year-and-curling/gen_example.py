import random

n = 1000
r = 1000

print(n, r)
for _ in range(n):
    x = random.randint(0, 10 * r)
    print(x, sep=' ')