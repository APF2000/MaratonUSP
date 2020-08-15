while True:    
    n_m = input().split()
    n = int(n_m[0])
    m = int(n_m[1])

    if n == 0 and m == 0:
        break

    ruas = []
    for i in range(m):
        vwp = input().split() 
        
        # Se P = 1 -> Mão única (V -> W)
        # Se P = 2 -> Mão dupla (V <-> W)
        ruas.append({'v': vwp[0], 'w': vwp[1], 'p': vwp[2]})

    print(ruas)