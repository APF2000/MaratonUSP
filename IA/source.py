# cat a.txt | python3 source.py a.txt a.out

import sys
from funcs import *

in_file = open(sys.argv[1], 'r')
out_file = open(sys.argv[2], 'w')

D,I,S,V,F, sts, cars, inters = pega_input(input)
#print(D,I,S,V,F, sts, cars, inters)

schedule = sol_batata(D,I,S,V,F, sts, cars, inters)

output = form_out(schedule)[:-1]
out_file.write(output)
#print(form_out(schedule))