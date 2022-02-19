n = int(input())
l = []
ings = set()

for _ in range(n):

    like = input()
    dislike = input()

    like = like[1:].split()
    dislike = dislike[1:].split()

    d = {'l': like, 'd': dislike}
    l.append(d)

    ings.update(like)
    for item in dislike:
        ings.discard(item)

print(len(ings), end=' ')
for ing in ings:
    print(ing, end=' ')
print()