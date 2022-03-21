class Solver():
    def __init__(self, arestas):
        self.arestas = arestas
        self.visitados = []
        self.nodes_faltantes = len(arestas)
        self.nodes_totais = len(arestas)
        self.volta_final = []

    def vai_e_volta(self, atual, alvo):
        arestas = self.arestas
        visitados = self.visitados

        # Todos os nos foram visitados
        if(self.nodes_faltantes == 0):
            if(atual == 1) or (1 in arestas[atual]):
                return True
            if atual in self.volta_final:
                return False

            self.volta_final.append(atual)
            if (len(self.volta_final) == self.nodes_totais):
                return False

            for node in arestas[atual].copy():
                if self.vai_e_volta(node, alvo):
                    return True
            return False

        if atual in visitados:
            index = visitados.index(atual)

            for el in visitados[index + 1:]:
                if el not in arestas[atual]:
                    arestas[atual].append(el)
                if atual not in arestas[el]:
                    arestas[el].append(atual)
            return False

        if(len(visitados) == self.nodes_totais):
            return False

        visitados.append(atual)
        self.nodes_faltantes -= 1
        for node in arestas[atual].copy():
            for visitado in visitados:
                if (visitado != atual) and (atual not in arestas[visitado]):
                    arestas[visitado].append(atual)
            if self.vai_e_volta(node, alvo):
                return True

        return False

while True:    
    n_m = input().split()
    n = int(n_m[0])
    m = int(n_m[1])

    if n == 0 and m == 0:
        break

    ruas = []
    arestas = {}
    for i in range(n):
        arestas[i + 1] = []
    
    for i in range(m):
        vwp = input().split() 
        v = int(vwp[0])
        w = int(vwp[1])
        p = int(vwp[2])
        
        # Se P = 1 -> Mão única (V -> W)
        # Se P = 2 -> Mão dupla (V <-> W)
        ruas.append({'v': v, 'w': w, 'p': p})

        arestas[v].append(w)
        if p == 2:
            arestas[w].append(v)
    
    solver = Solver(arestas)
    result = solver.vai_e_volta(1, 1)
    print("arestas: ", arestas)

    if result:
        print(1)
    else:
        print(0)