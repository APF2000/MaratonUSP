import sys
import math

def foo(orig_ing, count_dislikes, count_likes):
    dislikes = count_dislikes.get(orig_ing, 0)
    likes = count_likes.get(orig_ing, 0)

    print(dislikes, likes, orig_ing)

    return ( dislikes / (likes + dislikes), dislikes, -likes,  orig_ing )
    # for ing, dislikes in count_dislikes.items():
    #     likes = count_likes[ing]
    #     if dislikes >= min_dislike:
    #         ings.discard(ing)

n = int(input())
l = []

# pct_dislike = float(sys.argv[1])
# min_dislike = int(n * pct_dislike) 
#min_dislike = int(sys.argv[1])

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


foo2 = lambda x : foo(x, count_dislikes, count_likes)

ings = list(ings)
#print(ings)
ings = sorted(ings, key=foo2)
# print(ings)

percent = float( sys.argv[1] )
pos = math.ceil( len(ings) * percent )
ings = ings[:pos]
#print(ings)


print(len(ings), end=' ')
for ing in ings:
    print(ing, end=' ')
# print()

#print(count_dislikes, count_likes)

#print(len(ings))