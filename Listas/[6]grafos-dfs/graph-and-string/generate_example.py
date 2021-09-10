st = 'abbaccabca' * 50
size = len(st)

#grafo = []
content = ''
connections = 0

for i in range(size):
	for j in range(i + 1, size):
		if st[i] == 'b' or st[j] == 'b' or st[i] == st[j]:
			content += f'{i + 1} {j + 1}\n'
			connections += 1
			
print(f'{size} {connections}')
print(content)