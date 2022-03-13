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


people = []
skill_to_people = {}

projs = []
skill_to_projs = {}

all_skills = set()
f_names = ['a']#, 'b', 'c', 'd', 'e', 'f', 'g']
for f_name in f_names:
    in_file = open('in/' + f_name + '.in')
    out_file = open('out/' + f_name + '.out')

    read_in = lambda : in_file.readline().strip()
    read_out = lambda : out_file.readline().strip()


    # read input
    c, p = read_in().split()
    c, p = int(c), int(p)

    for i in range(c):
        name, n = read_in().split()
        n = int(n)
        person = Person(name, n)

        for _ in range(n):
            skill, sk_level = read_in().split()
            sk_level = int(sk_level)

            person.add_skill(skill, sk_level)

            l = skill_to_people.get(skill, [])
            l.append(i)
            skill_to_people[skill] = l

        people.append(person)

    for _ in range(p):
        line = read_in().split()
        name = line[0]
        d, s, b, r = line[1:]#map(line[1:], int)  
        d, s, b, r = int(d), int(s), int(b), int(r)

        proj = Project(name, d, s, b, r)

        for _ in range(r):
            skill, sk_level = read_in().split()
            sk_level = int(sk_level)     

            proj.add_skill(skill, sk_level)

        projs.append(proj)  


    # read output
    proj_sequence = []
    n_projs = int( read_out() )
    people_id_names = [ person.name for person in people ]
    for _ in range(n_projs):
        proj_name = read_out()

        proj_id_names = [ proj.name for proj in projs ]
        proj_id = proj_id_names.index(proj_name)

        #proj = projs[ proj_id ]
        info = {}
        info['proj_id'] = proj_id

        people_names = read_out().split()

        for p_name in people_names:
            p_id = people_id_names.index(p_name)

            l = info.get('people_ids', [])
            l.append(p_id)
            info['people_ids'] = l

        proj_sequence.append(info)

    # optimize