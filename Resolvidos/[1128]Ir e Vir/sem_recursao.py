# Usando o Algoritmo de Kosaraju

def vai_pra_todos(v_ini, arestas):
    fila, visitados = [v_ini], []
    while(len(fila) > 0):
        v_ini = fila.pop(0)
        for vertex in arestas[v_ini]:
            if not( vertex in fila or vertex in visitados ):
                fila.append(vertex)
        visitados.append(v_ini)
    
    if len(visitados) == len(arestas):
        return True
    return False

def vai_e_volta(v_ini, arestas, complementar):
    # Ida
    if(not vai_pra_todos(v_ini, arestas)):
        return 0
    # Volta
    if(not vai_pra_todos(v_ini, complementar)):
        return 0
    return 1    
        

while True:    
    n_m = input().split()
    n = int(n_m[0])
    m = int(n_m[1])

    if n == 0 and m == 0:
        break

    #ruas = []
    arestas = {}
    complementar = {}
    for i in range(n):
        arestas[i + 1] = []
        complementar[i + 1] = []

    
    for i in range(m):
        vwp = input().split() 
        v = int(vwp[0])
        w = int(vwp[1])
        p = int(vwp[2])
        
        # Se P = 1 -> Mão única (V -> W)
        # Se P = 2 -> Mão dupla (V <-> W)
        arestas[v].append(w)
        complementar[w].append(v)
        if p == 2:
            arestas[w].append(v)
            complementar[v].append(w)
    
    print( vai_e_volta(1, arestas, complementar) )