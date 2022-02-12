# https://storage.googleapis.com/coding-competitions.appspot.com/HC/2019/hashcode2019_qualification_task.pdf

# Judge: https://github.com/wbigger/google-hashcode-2019

import random

class Pic:
	def __init__(self, is_vertical, tags, id):
		self.is_vertical = is_vertical
		self.tags = tags
		self.id = id

	def __str__(self):
		return str(self.tags)

	def __repr__(self):
		return str(self.tags)

class Slide:
	def __init__(self, pics):
		self.tags = set()
		self.ids = set()
		for pic in pics:
			self.tags.update(pic.tags)
			self.ids.update({pic.id})

	def __str__(self):
		return str(self.tags)

	def __repr__(self):
		return str(self.tags)


def upper_bound(pics):
	all_tags = set()
	n_verts = 0
	n_horizs = 0

	for pic in pics:
		all_tags.update(pic.tags)
		if pic.is_vertical:
			n_verts += 1
		else:
			n_horizs += 1

	n_all_tags = len(all_tags)
	#print(n_all_tags, n_verts, n_horizs)

	return (n_all_tags // 3) * ( n_horizs + n_verts // 2 )

def optimize(pics):
	verts = [ pic for pic in pics if pic.is_vertical ]
	horzs = [ pic for pic in pics if not pic.is_vertical ]

	#print(verts)
	#print( horzs)

	random.shuffle(verts)
	#print(verts)

	horzs = [ Slide( [horz] ) for horz in horzs]
	new_verts = []
	for i in range(0, len(verts), 2):
		vert1 = verts[i]
		vert2 = verts[i + 1]
		new_verts.append( Slide( [vert1, vert2] ) )

	verts = new_verts
	#print(verts)
	#print(horzs)

	slides = horzs + verts

	random.shuffle(slides)
	first = slides[0]
	slides = slides[1:]
	print(slides)
	print(first)

	slide_show = [first]
	while len(slides) != 0:
		# slide_to_remove = None
		# max_score = -1
		# for slide in slides:
		# 	pass
		random.shuffle(slides)
		slide_to_remove = slides[0]
		slides = slides[1:]

		slide_show.append(slide_to_remove)

	print(slide_show)


f_is_vertical = lambda a : a == 'V'

n = int(input()) # photos
pics = []
for i in range(n):
	pic_info = input().split()
	is_vertical = f_is_vertical(pic_info[0])
	#n_tags = int(pic_info[1])

	tags = set(pic_info[2:])

	pics.append( Pic(is_vertical, tags, i) )

##print(pics)
##print(upper_bound(pics))
optimize(pics)