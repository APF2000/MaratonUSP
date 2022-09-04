
import random
from models import Pic, Slide
from calculations import *

# def optimize_original(pics):
	# verts = [ pic for pic in pics if pic.is_vertical ]
	# horzs = [ pic for pic in pics if not pic.is_vertical ]

	# ###print(verts)
	# ###print( horzs)

	# random.shuffle(verts)
	# ###print(verts)

	# horzs = [ Slide( [horz] ) for horz in horzs]
	# new_verts = []
	# for i in range(0, len(verts), 2):
	# 	vert1 = verts[i]
	# 	vert2 = verts[i + 1]
	# 	new_verts.append( Slide( [vert1, vert2] ) )

	# verts = new_verts
	# ###print(verts)
	# ###print(horzs)

	# slides = horzs + verts

	# random.shuffle(slides)
	# last_slide = slides[0]
	# slides = slides[1:]
	# ##print(slides)
	# ##print(last_slide)

	# slide_show = [last_slide]
	# random.shuffle(slides)
	# #print(len(slides))
	# #print(last_slide)

    # # greedy search for best next slide
	# while len(slides) != 0:
	# 	# slide_to_remove = None
	# 	# max_score = -1
	# 	# for slide in slides:
	# 	# 	pass
	# 	sub_slides = random.sample(slides, min(len(slides), 20))
	# 	#print(sub_slides)
	# 	new_score = -1
	# 	new_slide = None
	# 	for slide in sub_slides:
	# 		score = calc_score(last_slide.tags, slide.tags)
	# 		if score > new_score:
	# 			new_slide = slide
	# 			new_score = score

	# 	slides.remove(slide)
	# 	slide_show.append(new_slide)
	# #slide_show = slides
	
	# ##print('batata')	

	# #print(slide_show)

	# return slide_show

def init_individual(pics):
	
	verts = [ pic for pic in pics if pic.is_vertical ]
	horzs = [ pic for pic in pics if not pic.is_vertical ]

	###print(verts)
	###print( horzs)

	random.shuffle(verts)
	###print(verts)

	horzs = [ Slide( [horz] ) for horz in horzs]
	new_verts = []
	for i in range(0, len(verts), 2):
		vert1 = verts[i]
		vert2 = verts[i + 1]
		new_verts.append( Slide( [vert1, vert2] ) )

	###print(verts)
	###print(horzs)horzs

	slides = horzs + new_verts
	random.shuffle(slides)

	genes = []
	for slide in slides:
		for pic in slide.pics:
			genes.append(pic.id)
	
	# add last picture, even if does not suit in slide show
	if len(verts) % 2 == 1:
		genes.append(verts[-1].id)

	return (genes, slides)

def reproduce_parents(p1, p2):
	cross_over_id = random.randint(0, len(p1))

	return []

def create_slide_show_from_genes(genes):
	return []

QTTY_INDIV = 20
def optimize_genetic(pics):

	indivs = []
	for i in range(3):
		# reset last set of individuals
		aux_indivs = indivs
		indivs = []

		for _ in range(QTTY_INDIV):
			if i == 0:
				genes, slides = init_individual(pics)
			else:
				p1 = aux_indivs[0]
				p2 = aux_indivs[1]

				genes = reproduce_parents(p1, p2)
				slides = create_slide_show_from_genes(genes)

			score =  calc_score_from_slide_show( slides )
			indivs.append( ( genes, slides, score ) )

		for indiv in indivs:
			print(indiv)
		
		# sort by score
		indivs.sort(key = lambda indiv : indiv[2], reverse = True)

		print()

		for indiv in indivs:
			print(indiv)
	

	return []#indivs[0]

