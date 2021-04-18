#def eval_second():
#    pass

def score(D, fix, sts, cars, inters, schedule):
    ##print(f'sts {sts}, \ncars {cars} \ninters {inters}')
    #print('schedule', schedule)

    for st in sts.copy():
        size = sts[st]
        sts[st] = {'size': size, 'waiting': []}#set()}


    for car in cars.copy():
        path = cars[car]
        first = path[0]
        st_info = sts[first]#['size']
        cars[car] = { 'path': path, 'pos': { 'name': first, 'st': st_info, 'id': st_info['size'][2] - 1 }, 'score': 0 }

    ##print('cars', cars)

    for id in schedule.copy():
        prog = schedule[id]
        schedule[id] = {'prog': prog, 'green': 0, 'delta': 0}

    path = {}
    count = 0
    bkp_cars = {}
    passou_intersec = {}
    for inter in inters.copy():
        inters[inter] = { 'sts': inters[inter], 'passed': False }
        #print(f'inters[{inter}] = {inters[inter]}')

    for t in range(0, D):
        for inter in inters.copy():
            inters[inter]['passed'] = False

        #breakpoint()
        aux_cars = {}
        #print(f'---------------------------------------------------------------------------------------------------\n schedule')
        #print(f'cars antes = {cars}')
        #if t % 1000 == 0:
        #    for id in schedule:
        #        #print(f'{id} {schedule[id]}')

        for car in cars.copy():

            info = cars[car]

            path = info['path']
            pos = info['pos']

            #breakpoint()
            st_name = pos['name']
            size = pos['st']['size']
            #try:
            size_st = size[2]
            #except KeyError:
            #    breakpoint()

            end = size[1]
            id = pos['id']

            if True:#car == 885 or car == 695:
                ##print(f'schedule: {schedule}')
                #print(f'car {car} : {cars[car]}')
                #print(f'schedule da rua: {schedule[end]}')
                pass

            # If end of path
            #breakpoint()
            # Verificar tbm se ta no fim da rua
            if path[-1] == st_name and id >= size_st - 1: #(len(path) == 0):
                #print(f"carro {car} CHEGOU NO DESTINO")
                #print(f't={t}, D={D}, bonus={D-t}, fix={fix}, pountuacao antes={count}')
                score = fix + (D - t)
                count += score
                cars[car]['score'] = score
                bkp_cars[car] = cars[car]
                cars.pop(car)
                continue

            # Linhas perigosas abaixo: ponteiros no python
            # If end of st
            if id >= size_st - 1:
                id_green = schedule[end]['green']
                open_st = schedule[end]['prog'][id_green]['st']
                ###print('openst', open_st)
                wait = sts[st_name]['waiting']
                if car not in wait:
                    wait.append(car)
                    #print(f'carro {car} esperando ({wait}) na rua {st_name}')
                ###print('wait', wait)
                #breakpoint()
                if open_st == st_name: # Carro passa pra proxima rua
                    ##print('PASSANDO PRA PROXIMA RUA')

                    # Se tava na espera, tira, pq atravessou
                    if len(wait) > 0 and car == wait[0] and inters[end]['passed'] == False:#car in wait:

                        # Será que salva? (sim)
                        path.pop(0)
                        n_st = path[0]

                        info['pos'] = { 'name': n_st, 'st': sts[n_st], 'id': 0 }


                        ##print(f'')
                        #print(f'carro {car} saiu da espera ({wait}) na rua {st_name}; inters[{end}]={inters[end]}')
                        #wait.remove(car)
                        inters[end]['passed'] = True
                        wait.pop(0)
                # else:
                #     if car not in wait:
                #         wait.append(car)#wait.add(car)
                #         #print(f'carro {car} esperando ({wait}) na rua {st_name}')
            else: # Carro anda pela rua
                info['pos']['id'] += 1

            # Praq a linha abaixo ???
            aux_cars[car] = info

        for id in schedule:
            info = schedule[id]
            ###print('info antes', info)

            prog = info['prog']
            id_green = info['green']
            delta = info['delta']

            n_sts = len(prog)

            # Maior ou igual ou só maior?
            if delta >= prog[id_green]['t'] - 1:
                info['green'] = ( id_green + 1 ) % n_sts
                info['delta'] = 0
            else:
                info['delta'] += 1
            ###print('info depois', info)

        #print('t: ', t)
        #print(f'cars = {cars}')
    #print("bkp_cars: ", bkp_cars)
    return count, bkp_cars