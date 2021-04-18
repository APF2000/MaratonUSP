from math import floor
from math import gcd 
from functools import reduce

def pega_input(in_put):
    # Duration, num of Intersections, num of Streets, num of Vehicles, 
    D,I,S,V,F = map(int, in_put().split())

    inters = {}
    for i in range(I):
        inters[i] = []

    #print(f'inters {inters}')

    sts = {}
    for i in range(S):
        line = in_put().split()
        beg, end = map(int, line[:2])
        name = line[2]
        L = int(line[-1])

        sts[ name ] = ((beg), (end), (L))
        inters[end].append(name)

    cars  = {} 
    for i in range(V):
        line = in_put().split()
        P = int(line[0])

        cars[i] = line[1:]
    
    return D,I,S,V,F,sts,cars,inters

def sol_batata(D,I,S,V,F, sts, cars, inters):

    schedule = {}

    # Pra cada intersseccao, pegar as ruas e dizer que cada uma tem 1 s
    for inter in inters:
        aux = [ { 'st': st, 't': 1 } for st in inters[inter]]
        schedule[inter] = aux

    return schedule

def sol_ruim(D,I,S,V,F, sts, cars, inters):

    c_sts_cars = {}
    for name in sts:
        c_sts_cars[name] = 0

    for car in cars:
        path = cars[car]
        path = path[:-1]
        for st in path:
            c_sts_cars[st] += 1

    #print('c_sts_cars: ', c_sts_cars)
    c_inters_cars = {}
    for inter in inters:
        count = 0
        names = inters[inter]
        for name in names:
            count += c_sts_cars[name]
        c_inters_cars[inter] = count
    #print(c_inters_cars)

    schedule = {}
    for inter in inters:
        aux = []
        tempos = []
        for st in inters[inter]:
            cars = c_inters_cars[inter]
            if cars <= 0:
                t = 1
            else:
                t = floor(D * c_sts_cars[st] / cars)
                if t < 1:
                    t = 1

            tempos.append(t)
        
        mdc = mdc_varios(tempos)
        foo = (lambda t : t // mdc)
        tempos = list(map(foo, tempos))

        i = 0
        for st in inters[inter]:
            t = tempos[i]
            aux.append({ 'st': st, 't': t })
            i += 1
        
        schedule[inter] = aux
    #print(form_out(schedule))
    return schedule

def intermed_carros(D,I,S,V,F, sts, cars, inters):

    t_cars = []
    for car in cars:
        count = 0
        path = cars[car]
        #print('path', path)
        #print('sts', sts)

        for st in path:
            peso = sts[st][2]
            #print('rua', st, 'peso', peso)
            #print('count', count)
            count += peso
        #print('count', count)
        t_cars.append({'car': car, 'peso': count})

    foo = lambda el : el['peso']

    #print(t_cars)
    t_cars.sort(key=foo)
    #print(t_cars)
    return t_cars

def form_out(schedule):
    output = ''

    N = len(schedule)
    output += f"{N}\n"

    for inter in schedule:
        sts = schedule[inter]
        output += f"{inter}\n{len(sts)}\n"
        
        for st in sts:
            output += f"{st['st']} {st['t']}\n"
    
    return output

def mdc_varios(l):
    #functools.reduce(function, iterable[, initializer])
    return reduce(gcd, l)


def sol_top(D,I,S,V,F, sts, cars, inters):

    pesos_carros = intermed_carros(D,I,S,V,F, sts, cars, inters)
    #print(pesos_carros)

    c_sts_cars = {}
    for name in sts:
        c_sts_cars[name] = 0

    for car in cars:
        path = cars[car]
        path = path[:-1]
        for st in path:
            bla = 1
            for el in pesos_carros:
                if el['car'] == car:
                    bla = el['peso']
            c_sts_cars[st] += 1000000 / bla

    #print('c_sts_cars: ', c_sts_cars)
    c_inters_cars = {}
    for inter in inters:
        count = 0
        names = inters[inter]
        for name in names:
            count += c_sts_cars[name]
        c_inters_cars[inter] = count 
    #print(c_inters_cars)

    schedule = {}
    for inter in inters:
        aux = []
        tempos = []
        for st in inters[inter]:
            cars = c_inters_cars[inter]

            if cars <= 0:
                t = 1
            else:
                t = floor(D * c_sts_cars[st] / cars)
                if t < 1:
                    t = 1

            tempos.append(t)
        
        mdc = mdc_varios(tempos)
        foo = (lambda t : t // mdc)
        tempos = list(map(foo, tempos))

        i = 0
        for st in inters[inter]:
            t = tempos[i]
            aux.append({ 'st': st, 't': t })
            i += 1
        
        schedule[inter] = aux
    #print(form_out(schedule))
    return schedule