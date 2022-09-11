
# E1 = [[a,b],[c,d]]
# E2 = [[e,f],[g,h]]

def orient (E):

    if (E[0][0] - E[1][0] == 0):
        return 'vert'
    elif (E[0][1] - E[1][1] == 0):
        return 'hor'
    else:
        return 'normal'

def horNormal (hor, normal):

    xresp = (hor[0][0] + hor[1][0])/(2)

    a = (normal[1][1] - normal[0][1])/(normal[1][0] - normal[0][0])

    b = (normal[1][1] + normal[0][1])/2 + (1/a)*((normal[0][0] + normal[1][0])/2)

    yresp = -(1/a)*xresp + b

    return xresp, yresp

def horVert (hor, vert):
    xresp = (hor[0][0] + hor[1][0])/2

    yresp = (vert[0][1] +vert[1][1])/2

    return xresp, yresp

def normalVert (normal, vert):
    
    yresp = (vert[0][1] + vert[1][1])/2

    a = (normal[1][1] - normal[0][1])/(normal[1][0] - normal[0][0])

    b = (normal[1][1] + normal[0][1])/2 + (1/a)*((normal[0][0] + normal[1][0])/2)

    xresp = -((yresp-b)/(1/a))

    return xresp, yresp

def normal (E1, E2):

    a1 = (E1[1][1] - E1[0][1])/(E1[1][0] - E1[0][0])
    b1 = (E1[1][1] + E1[0][1])/2 + (1/a1)*((E1[0][0] + E1[1][0])/2)

    a2 = (E2[1][1] - E2[0][1])/(E2[1][0] - E2[0][0])
    b2 = (E2[1][1] + E2[0][1])/2 + (1/a2)*((E2[0][0] + E2[1][0])/2)

    xresp = (b2-b1)/((1/a2)-(1/a1))
    yresp = -(1/a1)*xresp + b1

    return xresp, yresp

def main (E1, E2):

    orient1 = orient(E1)
    orient2 = orient(E2)

    if (orient1 == 'vert'):
        if (orient2 == 'hor'):
            return horVert(E2, E1)
        else:
            return normalVert(E2, E1)

    elif (orient1 == 'hor'):
        if (orient2 == 'vert'):
            return horVert(E1, E2)
        else:
            return horNormal(E1, E2)

    else:
        if (orient2 == 'hor'):
            return horNormal(E2, E1)
        elif (orient2 == 'vert'):
            return normalVert(E1, E2)
        else:
            return normal(E1,E2)



casos = int(input())
for i in range (casos):
    E1 = []
    E2 = []

    temp = (input()).split()
    temp = [float(item) for item in temp]
    E1.append(temp)

    temp = (input()).split()
    temp = [float(item) for item in temp]
    E2.append(temp)

    temp = (input()).split()
    temp = [float(item) for item in temp]
    E1.append(temp)

    temp = (input()).split()
    temp = [float(item) for item in temp]
    E2.append(temp)

    resp = main(E1, E2)
    resp = "Caso #%d %.2f %.2f" % ((i+1), resp[0], resp[1])
    print(resp)