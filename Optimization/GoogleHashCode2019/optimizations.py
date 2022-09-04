
import random
from models import Pic, Slide
from calculations import *

QTTY_INDIV = 20

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

# from genes of parents define genes from children
def reproduce_parents(p1, p2):
	print('reproduce')
	print(p1, p2)
	n = len(p1)
	children = []

	for _ in range(QTTY_INDIV // 2):
		child1, child2 = p1, p2

		cross_over_id = random.randint(0, n)

		print(child1)
		print(child2)

		print(cross_over_id)

		# swap divided chromossomes
		aux_child1, aux_child2 = child1, child2
		child1 = aux_child1[:cross_over_id] + aux_child2[cross_over_id:]
		child2 = aux_child2[:cross_over_id] + aux_child1[cross_over_id:]

		print(child1)
		print(child2)

		children += [child1, child2]

	print(children)

	return children

def create_slide_show_from_genes(genes):
	return []

def optimize_genetic(pics):

	indivs = []
	for i in range(2):
		# reset last set of individuals
		aux_indivs = indivs
		indivs = []

		for _ in range(QTTY_INDIV):
			if i == 0:
				genes, slides = init_individual(pics)
			else:
				best_indiv = aux_indivs[0]
				best_genes = tuple(best_indiv[0])

				# find second best, but with different genetics
				sec_best_id = 1
				for indiv in aux_indivs[1:]:
					sec_best_genes = tuple(indiv[0])

					# print("compare")
					# print(best_genes)
					# print(sec_best_genes)

					# found different individual
					if sec_best_genes != best_genes:
						break

					sec_best_id += 1
				sec_best_indiv = aux_indivs[sec_best_id]

				# get gene from best score individuals
				p1 = best_indiv[0]
				p2 = sec_best_indiv[0]

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

