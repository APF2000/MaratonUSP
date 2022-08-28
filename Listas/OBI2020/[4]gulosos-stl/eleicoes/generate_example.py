import random

l = [9, 27, 43, 8]
ls = []
qts = [ 1000, 1500, 6000, 500 ]
sum_qts = 0

for i in range(len(l)):
	cand = l[i]
	qt = qts[i]
	ls += qt * [cand]
	sum_qts += qt

ls = random.sample(ls, len(ls))

print(sum_qts)
for el in ls:
	print(el)