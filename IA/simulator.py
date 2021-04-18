#def eval_second():
#    pass
def change_structure(sts, cars, schedule):
    for st in sts.copy():
        size = sts[st]
        sts[st] = {'size': size, 'waiting': []}#set()}


    for car in cars.copy():
        path = cars[car]
        first = path[0]
        st_info = sts[first]#['size']
        cars[car] = { 'path': path, 'pos': { 'name': first, 'st': st_info, 'id': st_info['size'][2] - 1 }, 'score' : 0 }
        #print(cars[car])

    ####print('cars', cars)

    for id in schedule.copy():
        prog = schedule[id]
        schedule[id] = {'prog': prog, 'green': 0, 'delta': 0}

def score(D, fix, sts, cars, inters, schedule):
    ###print(f'sts {sts}, \ncars {cars} \ninters {inters}')
    ##print('schedule', schedule)
    change_structure(sts, cars, schedule)
    cp_cars = cars.copy()
    path = {}
    count = 0
    for t in range(D):
        aux_cars = {}
        ##print(f'---------------------------------------------------------------------------------------------------\n schedule')
        ##print(f'cars antes = {cars}')
        for id in schedule:
            pass
            ###print(f'{id} {schedule[id]}')

        for car in cars.copy():
            #print(f'car {car} : {cars[car]}')

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

            # If end of path
            #breakpoint()
            if path[-1] == st_name: #(len(path) == 0):
                ##print(f"carro {car} CHEGOU NO DESTINO")
                score_car = fix + (D-t)
                count += score_car
                cars[car]['score'] = score_car
                cars.pop(car)
                continue

            # Linhas perigosas abaixo: ponteiros no python
            # If end of st
            if id >= size_st - 1:
                id_green = schedule[end]['green']
                open_st = schedule[end]['prog'][id_green]['st']
                ####print('openst', open_st)
                wait = sts[st_name]['waiting']
                ####print('wait', wait)
                #breakpoint()
                if open_st == st_name: # Carro passa pra proxima rua
                    ###print('PASSANDO PRA PROXIMA RUA')

                    # Será que salva? (sim)
                    path.pop(0)
                    n_st = path[0]

                    info['pos'] = { 'name': n_st, 'st': sts[n_st], 'id': 0 }

                    # Se tava na espera, tira, pq atravessou
                    if car in wait:
                        wait.remove(car)
                else:
                    if car not in wait:
                        wait.append(car)#wait.add(car)
            else: # Carro anda pela rua
                info['pos']['id'] += 1

            # Praq a linha abaixo ???
            aux_cars[car] = info

        for id in schedule:
            info = schedule[id]
            ####print('info antes', info)

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
            ####print('info depois', info)

        ##print('t: ', t)
        ##print(f'cars = {cars}')
    ##print("cars = ", cars)
    cars = cp_cars
    return count, cars