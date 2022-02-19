import sys

n = int(input())
l = []

pct_dislike = float(sys.argv[1])
min_dislike = int(n * pct_dislike) 

count_likes = {}
count_dislikes = {}

ings = set()

for _ in range(n):

    like = input()
    dislike = input()

    like = like[1:].split()
    dislike = dislike[1:].split()

    # default 0
    for item in like:
        count_likes[item] = count_likes.get(item, 0) + 1 

    for item in dislike:
        count_dislikes[item] = count_dislikes.get(item, 0) + 1 

    ings.update(like)
    # for item in dislike:
    #     ings.discard(item)

for ing, count in count_dislikes.items():
    if count >= min_dislike:
        ings.discard(ing)

print(len(ings), end=' ')
for ing in ings:
    print(ing, end=' ')
print()

#print(count_dislikes, count_likes)
