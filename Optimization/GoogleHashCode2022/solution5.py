from collections import OrderedDict
import random

class Skill:
    def __init__(self, name, level):
        self.mentoria = False
        self.name = name
        self.level = level
        
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
        self.mentorable_sks = OrderedDict()

        self.skill_to_person = OrderedDict()

        self.people = set()

    def add_skill(self, name, level):
        self.skills[name] = level 
        self.mentorable_sks[name] = False

    def add_person(self, skill, person):
        self.skill_to_person[skill] = person
        self.people.add(person.name)
        self.mentoria(person)

    def mentoria(self, person):
        for skill in person.skills:
            if skill in self.skills.keys() and person.skills[skill] >= self.skills[skill]:
                self.mentorable_sks[skill] = True

    def __str__(self):
        return self.name + ' : skills' + str(self.skills) + ' \nblalal' + str(self.skill_to_person)

    def __repr__(self):
        return self.__str__() 



###print(input().split())
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

##print(people)
##print(skill_to_people)

# ordem crescente de skill
for skill, people2 in skill_to_people.items():
    l = sorted(people2, key = ( lambda id_p : people[id_p].skills[skill] ) )
    skill_to_people[skill] = l

##print(skill_to_people)

projs = []
skill_to_projs = {}
all_skills = set()
for i in range(p):
    line = input().split()
    name = line[0]
    d, s, b, r = line[1:]#map(line[1:], int)  
    d, s, b, r = int(d), int(s), int(b), int(r)

    proj = Project(name, d, s, b, r)

    for _ in range(r):
        skill, sk_level = input().split()
        sk_level = int(sk_level)     

        proj.add_skill(skill, sk_level)

        l = skill_to_projs.get(skill, [])
        l.append(i)
        skill_to_projs[skill] = l

        all_skills.add(skill)

    projs.append(proj)   

#print(skill_to_projs)
##print(projs)

# ordem crescente de skill
for skill, projs2 in skill_to_projs.items():
    l = sorted(projs2, key = ( lambda id_p : projs[id_p].skills[skill] ) )
    skill_to_projs[skill] = l


#print(skill_to_projs)

#projs.sort( key = ( lambda proj : (-proj.duration, proj.score, proj.best,  proj.name) ) )
##print(projs)

n_valid_projs = 0
output = ''

# for proj in projs:
#     for person in people:
#         proj.mentoria(person) # define quais skills sao mentoraveis

    #print('mentskills: ', proj.mentorable_sks)

#print(projs)
person_to_count_projs = {}
# all_skills = random.shuffle(all_skills)
for skill in all_skills:
    projs2 = skill_to_projs[skill]
    people2 = skill_to_people[skill]
    #print('--------')
    #print('people2', people2)
    #print('projs2', projs2)
    #print(skill)

    last_person_id = 0
    for id_proj in projs2:
        proj = projs[id_proj]
        #print('================')
        #print('skills', proj.skills)
        #print('projs', projs)
        #print('idproj', id_proj)
        #print('proj', proj)



        min_level = proj.skills[skill]
        if proj.mentorable_sks[skill] == True:
            min_level -= 1

        #print('skill', skill)
        #print('people', people)
        for ii in range(last_person_id, len(people2)):
            id_person = people2[ii]
            person = people[id_person]
            #print('idperson', id_person)
            #print(person)
            
            level = person.skills[skill]
            if level >= min_level and person.name not in proj.people:
                proj.add_person(skill, person)
                #print('add person')
                last_person_id = (ii + 1) % len(people2)
                # print('people:', proj.people)
                break
        
        #print('skill: %s, skilltoperson (%s): ' % (skill, proj.name), proj.skill_to_person)

#print(projs)
output = ''
i = 0
for proj in projs:
    if len(proj.skill_to_person) == proj.reqs:
        output += '\n' + proj.name + '\n'
        for skill in proj.skills:
            output += proj.skill_to_person[skill].name  + ' '
        i += 1
n_valid_projs = i

output = str(n_valid_projs) + output
print(output.strip('\n\n'))