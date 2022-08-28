cnt_like = {}
cnt_dislike = {}

files = ["a","b","c","d","e"]

for file in files:
    with open("in/"+ file +".in","r") as inp:
        with open("out/" + file+".out","r") as out:
            ing = out.read().split()
            ing = set(ing[1:])
            l = inp.readlines()
            for i in range(len(l)):
                l[i] = l[i].rstrip()
            N = int(l[0])
            ans = 0
            for i in range(1,N + 1):
                likes = l[2*i-1][1:].split()
                dislikes = l[2*i][1:].split()
                Ok = True
                for like in likes:
                    if like not in ing:
                        Ok = False
                for dislike in dislikes:
                    if dislike in ing:
                        Ok = False
                if Ok:
                    ans += 1
            print(ans)
