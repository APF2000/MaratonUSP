ja_calc = {}

def qtde_recipientes(tree, index):

    if index == '-1': 
        return 0

    father = tree[index]
    prod = father['prod']

    if prod in ja_calc.keys():
        return ja_calc[prod]

    right = father['dir']
    left = father['esq']

    max_r = max([qtde_recipientes(tree, right['id']), qtde_recipientes(tree, left['id'])])
    min_r = min([qtde_recipientes(tree, right['id']), qtde_recipientes(tree, left['id'])])

    if max_r == min_r:
        ja_calc[prod] = max_r + 1
        return max_r + 1

    ja_calc[prod] = max_r + 1
    return max_r


n = int(input())
while n != 0:
    reacoes = []
    for i in range(n):
        formula = input().split()

        reag1 = formula[0]
        reag2 = formula[2]
        produto = formula[4]

        id1, id2 = '-1', '-1'
        for j in range(i):
            if reacoes[j]['prod'] == reag1:
                id1 = j

            if reacoes[j]['prod'] == reag2:
                id2 = j

        reacoes.append({'prod': produto, 'esq': {'id': id1, 'nome': reag1}, 'dir': {'id': id2, 'nome': reag2}})
    
    #print(reacoes)
    print("%s requires %d containers" % (reacoes[-1]['prod'], qtde_recipientes(reacoes, -1)))

    n = int(input())

'''
1
2H + O -> Water

5
A + B -> T1
C + D -> T2
E + F -> T3
T2 + T3 -> T4
T4 + T1 -> P

3
a + b -> ab
ab + c -> abc
abc + d -> abcd
0
'''