tab = {
    61 : "Brasilia",
    71 : "Salvador"
}

ddd = int(input())

if ddd in tab.keys():
    print(tab[ddd])
else:
    print("DDD nao encontrado")