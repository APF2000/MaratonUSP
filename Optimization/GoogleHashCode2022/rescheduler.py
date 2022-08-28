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

        self.first_day_of_work = 0

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
        return self.name + ' : skills' + str(self.skills) + ' \nskill_to_person: ' + str(self.skill_to_person)

    def __repr__(self):
        return self.__str__() 


people = []
skill_to_people = {}

projs = []
skill_to_projs = {}

all_skills = set()
f_names = ['a', 'b', 'c', 'd', 'e', 'f', 'g']
for f_name in f_names:
    print('-----------')
    print('file: ', f_name)

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
    proj_infos = []
    n_projs = int( read_out() )
    people_id_names = [ person.name for person in people ]
    for _ in range(n_projs):
        proj_name = read_out()

        proj_id_names = [ proj.name for proj in projs ]
        proj_id = proj_id_names.index(proj_name)

        #proj = projs[ proj_id ]
        proj_info = {}
        proj_info['proj_id'] = proj_id

        people_names = read_out().split()

        for p_name in people_names:
            p_id = people_id_names.index(p_name)

            l = proj_info.get('people_ids', [])
            l.append(p_id)
            proj_info['people_ids'] = l

        proj_infos.append(proj_info)

    # schedule
    schedule = {}
    worker_ids = set()
    for proj_info in proj_infos:
        proj_id = proj_info['proj_id']
        proj = projs[ proj_id ]
        new_people_ids = set( proj_info['people_ids'] )
        # print('new_people_ids', new_people_ids)

        id_day = 0
        while True:
            day_info = schedule.get(id_day, {})
            active_people_ids = day_info.get('active_people_ids', set())
            active_proj_ids = day_info.get('active_proj_ids', set())

            #print('active_people_ids', active_people_ids)

            conflict_people_ids = active_people_ids.intersection( new_people_ids ) 
            #print('conflict_people_ids', conflict_people_ids)
            if len(conflict_people_ids) == 0:
                proj.first_day_of_work = id_day

                for proj_day in range(proj.duration):
                    this_day = id_day + proj_day
                    all_people_ids = active_people_ids.union( new_people_ids )
                    all_proj_ids = active_proj_ids.union( { proj_id } )

                    worker_ids = worker_ids.union( all_people_ids )

                    day_info['active_people_ids'] = all_people_ids
                    day_info['active_proj_ids'] = all_proj_ids
                    schedule[this_day] = day_info
                break

            id_day += 1

        # print('proj', proj)
        # print('id_day', id_day)

    #print('schedule', schedule)
    #print('worker_ids', worker_ids)
    non_worker_ids = set([i for i in range(len(people))]).difference(worker_ids)
    print('non_worker_ids', non_worker_ids)
    for p_id in non_worker_ids:
        print(p_id, people[p_id])

