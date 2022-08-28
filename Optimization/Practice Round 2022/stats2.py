import os

files = ["a","b","c","d","e"]
best_scores = [0 for _ in files]
min_dislikes = [0 for _ in files]
# for f_name in files:
#     best_score[f_name] = 0

for i in range(10):
    #print("-------------------")
    for f_name in files:
        cmd = "cat in/%s.in | python3 stats.py %d > out/%s.out" % (f_name, i, f_name)
        #print(cmd)
        os.system(cmd)
    #print('batata')
    os.system("python3 score.py > tmp.txt")

    scores = open('tmp.txt', 'r').read().strip()
    #print(scores)
    scores = [int(score) for score in scores.split('\n')]
    for j in range(len(files)):
        if(scores[j] > best_scores[j]):
            best_scores[j] = scores[j]
            min_dislikes[j] = i

print(best_scores)
print(min_dislikes)

for i, f_name in enumerate(files):
    cmd = "cat in/%s.in | python3 stats.py %d > out/%s.out" % (f_name, min_dislikes[i], f_name)
    print(cmd)
    os.system(cmd)

