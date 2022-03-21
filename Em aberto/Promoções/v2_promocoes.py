
def soma_permutacao(perm, promos, by):
	#vec = [perm[i] * promos[i][by] for i in range(n_promos)]
	#import pdb;pdb.set_trace()
	vec = [promos[index][by] for index in perm]
	return sum(vec)

while(True):
	try:
		n_m = input()
	except EOFError:
		break

	n_m = n_m.split()
	n_promos, m_latas = int(n_m[0]), int(n_m[1])

	promos = []
	for i in range(n_promos):
		q_v = input().split()
		promos.append({'qtde_promo': int(q_v[0]), 'valor': int(q_v[1])})

	#print(promos)
	promos.sort(reverse = True, key = (lambda x: (x['valor'] / x['qtde_promo'], x['qtde_promo'])))
	#print(promos)
	#print()
	#print([x['valor'] / x['qtde_promo'] for x in promos])

	stack = [0]
	unstacked = False
	last_index = len(promos) - 1
	#custo = [0]
	for i in range(10**10):
		if (soma_permutacao(stack, promos, 'qtde_promo') == m_latas):
			open('aaaaaaaddda.txt', 'a').write(str(stack)+ str(soma_permutacao(stack, promos, 'valor')) + str(soma_permutacao(stack, promos, 'qtde_promo')) + str(m_latas) + '\n')
			
			

		if stack[-1] == 7:
			pass#import pdb;pdb.set_trace()

		#print(soma_permutacao(stack, promos, 'qtde_promo'), m_latas)

		if unstacked:
			stack.append(0)
			unstacked = False
			continue

		if(soma_permutacao(stack, promos, 'qtde_promo') < m_latas):
			stack.append(0)
			continue

		stack[-1] += 1
		if stack[-1] > last_index:
			while stack[-1] > last_index:
				stack.pop(-1)
				stack[-1] += 1
			unstacked = True


	print(soma_permutacao(stack, promos, 'valor'))
	#open('aaaaaaaddda.txt', 'a').write(str(soma_permutacao(stack, promos, 'valor')) + ' ' + str(n_m) + '\n')
	#print(stack)    
	#print(soma_permutacao(stack, promos, 'qtde_promo'), m_latas)   



# Caso de teste
'''
8 70
4 9
5 1
5 18
2 3
3 11
3 9
3 3
3 6

3 67
4 9
3 10
3 8


9 69
3 8
2 10
3 18
2 4
1 11
4 9
2 2
3 3
1 17

4 9
1 2
3 4
5 6
7 8

10 34
5 11
3 6
3 11
1 10
2 14
4 19
3 8
5 2
5 16
4 5
'''

