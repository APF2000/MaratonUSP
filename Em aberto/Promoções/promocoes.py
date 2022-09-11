
def soma_permutacao(perm, promos, by):
    vec = [perm[i] * promos[i][by] for i in range(n_promos)]
    return sum(vec)

try:
    while(True):
        n_m = input()
        n_m = n_m.split()
        n_promos, m_latas = int(n_m[0]), int(n_m[1])

        promos = []
        for i in range(n_promos):
            q_v = input().split()
            promos.append({'qtde_promo': int(q_v[0]), 'valor': int(q_v[1])})

        print(promos)
        promos.sort(reverse = True, key = (lambda x: x['qtde_promo']))
        print(promos)

        latas_iniciais = m_latas // promos[0]['qtde_promo']
        permutacoes = [[i] for i in range(latas_iniciais + 1)]
        for p in range(1, len(promos)):
            promo = promos[p]

            n = len(permutacoes)
            for i in range(n):
                index = n - 1 - i 
                permutacao = permutacoes[index]
                soma = m_latas

                for j in range(p - 1):
                    qtde_kits = permutacao[j]
                    soma -= qtde_kits * promos[j]['qtde_promo']

                aux = []
                for qtde_kits in range(soma // promo['qtde_promo'] + 1):
                    aux.append(permutacao + [qtde_kits])

                permutacoes.pop(index)
                permutacoes += aux 

        aux_permutacoes = []
        for permutacao in permutacoes:

            soma = soma_permutacao(permutacao, promos, by = 'qtde_promo')
   
            if soma == m_latas:
                aux_permutacoes.append(permutacao)
        permutacoes = aux_permutacoes

        lucros = [soma_permutacao(permutacao, promos, by = 'valor') for permutacao in permutacoes]
        print(max(lucros))

except EOFError:
    pass

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

