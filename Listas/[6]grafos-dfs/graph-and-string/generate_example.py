import random
import sys

example_name = sys.argv[1]

#st = 'abbaccabca' * 50
N = 500
letters = ['a', 'b', 'c']
st = ''.join(random.choices(letters, k=N))
size = len(st)

in_file = open(example_name + 'input.txt', 'w')
out_file = open(example_name + 'output.txt', 'w')

#grafo = []
content = ''
connections = 0

for i in range(size):
	for j in range(i + 1, size):
		if st[i] == 'b' or st[j] == 'b' or st[i] == st[j]:
			content += f'{i + 1} {j + 1}\n'
			connections += 1

in_file.write(f'{size} {connections}\n')
in_file.write(content)

out_file.write(f'Yes\n{st}')