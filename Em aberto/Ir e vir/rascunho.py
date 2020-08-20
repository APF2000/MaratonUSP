class Solver():
    def __init__(self, arestas):
        self.arestas = arestas
        self.visitados = []
        self.nodes_faltantes = len(arestas)

    def vai_e_volta(self, atual, alvo):
        #import pdb; pdb.set_trace()
        #nodes_faltantes = len(self.arestas) - len(self.visitados)

        if(self.nodes_faltantes == 0 and 1 in self.arestas[atual]):    
            return True

        if atual in self.visitados:
            index = self.visitados.index(atual)
            import pdb; pdb.set_trace()

            for el in self.visitados[index + 1:]:
                if el not in self.arestas[atual]:
                    self.arestas[atual].append(el)
                if atual not in self.arestas[el]:
                    self.arestas[el].append(atual)

            return False

        if(len(self.visitados) == len(self.arestas)):
            return False

        self.visitados.append(atual)
        self.nodes_faltantes -= 1
        for node in self.arestas[atual].copy():
            import pdb; pdb.set_trace()
            for visitado in self.visitados:
                if (visitado != atual) and (atual not in self.arestas[visitado]):
                    self.arestas[visitado].append(atual)
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
    
    #import pdb; pdb.set_trace()
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

    #import pdb; pdb.set_trace()
    print(ruas)