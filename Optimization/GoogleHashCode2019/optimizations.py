
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

	chromos = []
	for slide in slides:
		for pic in slide.pics:
			chromos.append(pic.id)
	
	# add last picture, even if does not suit in slide show
	if len(verts) % 2 == 1:
		chromos.append(verts[-1].id)

	return (chromos, slides)

# from genes of parents define genes from children
def reproduce_parents(p1, p2):
	print('reproduce')
	print(p1, p2)
	n = len(p1)
	children = []

	for _ in range(QTTY_INDIV // 2):
		child1, child2 = p1, p2

		cross_over_id = random.randint(0, n)

		# print(child1)
		# print(child2)

		# print(cross_over_id)

		# swap divided chromossomes
		aux_child1, aux_child2 = child1, child2
		child1 = aux_child1[:cross_over_id] + aux_child2[cross_over_id:]
		child2 = aux_child2[:cross_over_id] + aux_child1[cross_over_id:]

		# print(child1)
		# print(child2)	

		repeated_ids1 = [ id for id in range(len(child1)) if child1.count(id) > 1 ]
		repeated_ids2 = [ id for id in range(len(child2)) if child2.count(id) > 1 ]

		random.shuffle(repeated_ids1)
		random.shuffle(repeated_ids2)
		# print("repeated")
		# print(repeated_ids1)
		# print(repeated_ids2)

		for i in range(len(repeated_ids1)):
			pos_id1 = child1.index(repeated_ids1[i])
			pos_id2 = child2.index(repeated_ids2[i])

			# swap repeated ids
			aux = child1[pos_id1]
			child1[pos_id1] = child2[pos_id2]
			child2[pos_id2] = aux

		# print("corrected:")
		# print(child1)
		# print(child2)	

		children += [child1, child2]

	# print(children)

	return children

def create_slide_show_from_chromo(chromo, pics):

	print("-----------------------")
	print(chromo)

	last_vert_pic = None
	slide_show = []
	for gene in chromo:
		print(pics)
		#print("id_gene: " + str(id_gene))
		print("gene: " + str(gene))
		print()

		pic = pics[gene]
		pics_in_slide = [ pic ]

		if pic.is_vertical:
			if last_vert_pic == None:
				last_vert_pic = pic
				continue
			else:
				pics_in_slide.append( last_vert_pic )
				last_vert_pic = None

		print("slide show before: ")
		for slide in slide_show:
			print(slide)

		slide_show.append( Slide(pics_in_slide) )

		print("slide show after: ")
		for slide in slide_show:
			print(slide)
	
	print(chromo)
	print("new slide show: ")
	for slide in slide_show:
		print(slide)

	return slide_show

def optimize_genetic(pics):

	indivs = []
	for i in range(2):
		# reset last set of individuals
		aux_indivs = indivs
		indivs = []

		for _ in range(QTTY_INDIV):
			if i == 0:
				chromos, slides = init_individual(pics)
			else:
				best_indiv = aux_indivs[0]
				best_chromos = tuple(best_indiv[0])

				# find second best, but with different genetics
				sec_best_id = 1
				for indiv in aux_indivs[1:]:
					sec_best_chromos = tuple(indiv[0])

					# print("compare")
					# print(best_chromos)
					# print(sec_best_chromos)

					# found different individual
					if sec_best_chromos != best_chromos:
						break

					sec_best_id += 1
				sec_best_indiv = aux_indivs[sec_best_id]

				# get gene from best score individuals
				p1 = best_indiv[0]
				p2 = sec_best_indiv[0]

				chromos = reproduce_parents(p1, p2)
				for chromo in chromos:
					slides = create_slide_show_from_chromo(chromo, pics)

			score =  calc_score_from_slide_show( slides )
			indivs.append( ( chromos, slides, score ) )

		# for indiv in indivs:
		# 	print(indiv)
		
		# sort by score
		indivs.sort(key = lambda indiv : indiv[2], reverse = True)

		# print()

		# for indiv in indivs:
		# 	print(indiv)
	

	return []#indivs[0]

