import heapq

def foo(graph, my_id, likes, count_dislikes):
    for ing_like in likes[my_id]:
        people = count_dislikes.get(ing_like, set())
        graph[my_id].update(people) # add discord people
        for person in people:
            l = graph[person]
            l.add(my_id)
            graph[person] = l # mark me as discord

# def foo2(graph):


n = int(input())
l = []

count_likes = {}
count_dislikes = {}

likes = []
dislikes = []

graph = [set() for _ in range(n)]

#ings = []

for i in range(n):

    like = input()
    dislike = input()

    like = like[1:].split()
    dislike = dislike[1:].split()

    likes.append(like)
    dislikes.append(dislike)

    # default 0
    for item in like:
        l = count_likes.get(item, set())
        l.add(i)
        count_likes[item] = l

    for item in dislike:
        l = count_dislikes.get(item, set())
        l.add(i)
        count_dislikes[item] = l

    #ings.update(like)

for i in range(n):
    foo(graph, i, likes, count_dislikes)
    foo(graph, i, dislikes, count_likes)

    
#print(graph)

chosen_people = [False for _ in range(n)]

#print(graph)

#H = [21,1,45,78,3,5]
# Use heapify to rearrange the elements
g_sorted = [(len(el[1]), el[0]) for el in enumerate(graph)]
heapq.heapify(g_sorted)
# print(g_sorted)
# heapq.heappop(g_sorted)
# print(g_sorted)

while len(g_sorted) > 0:
    #print('asiusdhusd')
    should_break = True
    for i, s in enumerate(graph):
        if len(s) > 0:
            should_break = False
            break

    if should_break:
        #print('alo')
        break

    # g_sorted = enumerate(graph)
    # g_sorted = sorted(g_sorted, key=(lambda el : len(el[1]) ) )
    worst_node = heapq.heappop(g_sorted)
    my_id = worst_node[1]
    nbors = graph[my_id]

    #print(g_sorted)

    for nbor in nbors:
        nbors2 = graph[nbor]
        for nbor2 in nbors2:
            graph[nbor].discard(my_id)

    graph[my_id] = set()
    chosen_people[my_id] = True

#print(graph)
#print(chosen_people)
ings = set()
for i, chosen in enumerate(chosen_people):
    if chosen:
        #print(i)
        ings.update(likes[i])

print(len(ings), end=' ')
for ing in ings:
    print(ing, end=' ')
print()

# print(count_dislikes, count_likes)
# print(likes)
# print(dislikes)

