from collections import OrderedDict

class Skill:
    def __init__(self):
        pass
        
class Person:
    def __init__(self, name, n):
        self.name = name
        self.n = n
        self.skills = {}

    def add_skill(self, name, level):
        self.skills[name] = level 

    def __str__(self):
        return self.name + ' : ' + str(self.skills)

    def __repr__(self):
        return self.__str__() 

class Project:
    def __init__(self, name, d, s, b, r):
        self.name = name
        
        self.duration = d
        self.score = s
        self.best = b
        self.reqs = r

        self.skills = OrderedDict()

    def add_skill(self, name, level):
        self.skills[name] = level 

    def __str__(self):
        return self.name + ' : ' + str(self.skills)

    def __repr__(self):
        return self.__str__() 



##print(input().split())
c, p = input().split()#map(input().split(), int)
c, p = int(c), int(p)

people = []
skill_to_people = {}
for i in range(c):
    name, n = input().split()
    n = int(n)
    person = Person(name, n)

    for _ in range(n):
        skill, sk_level = input().split()
        sk_level = int(sk_level)

        person.add_skill(skill, sk_level)

        l = skill_to_people.get(skill, [])
        l.append(i)
        skill_to_people[skill] = l

    people.append(person)

#print(people)
#print(skill_to_people)

# ordem crescente de skill
for skill, people2 in skill_to_people.items():
    l = sorted(people2, key = ( lambda id_p : people[id_p].skills[skill] ) )
    skill_to_people[skill] = l

#print(skill_to_people)

projs = []
for _ in range(p):
    line = input().split()
    name = line[0]
    d, s, b, r = line[1:]#map(line[1:], int)  
    d, s, b, r = int(d), int(s), int(b), int(r)

    proj = Project(name, d, s, b, r)

    for _ in range(r):
        skill, sk_level = input().split()
        sk_level = int(sk_level)     

        proj.add_skill(skill, sk_level)

    projs.append(proj)   

#print(projs)

projs.sort( key = ( lambda proj : proj.best ) )
#print(projs)

n_valid_projs = 0
output = ''
for proj in projs:
    is_valid_proj = True
    #print('-----------\nproj: ', proj.name)

    chosen_people = []
    for skill, sk_level in proj.skills.items():
        ids_people = skill_to_people[skill]

        #print('ids_people', ids_people)
        #print('skill', skill)
        #print('sklevel', sk_level)

        id_p = ids_people[-1]
        for id_person in reversed(ids_people):
            level2 = people[id_person].skills[skill]
            if sk_level > level2:
                is_valid_proj = False
                break

            if id_person not in chosen_people:
                chosen_people.append(id_person)
                id_p = id_person
                break

        level = people[id_p].skills[skill]# most skill

        if sk_level > level:
            is_valid_proj = False
            break

    if is_valid_proj and len(chosen_people) == proj.reqs:
        n_valid_projs += 1
        output += (proj.name) + '\n'
        for id_p in chosen_people:
            #print('id_p', id_p)
            output += (people[id_p].name + ' ')
        output += '\n'

output = str(n_valid_projs) + '\n' + output
print(output.strip('\n\n'))
