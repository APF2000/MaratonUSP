
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
	###print(n_all_tags, n_verts, n_horizs)

	return (n_all_tags // 3) * ( n_horizs + n_verts // 2 )

def calc_score(tags1, tags2):
	intersec = tags1.intersection(tags2)
	intersec = len(intersec)

	exclusive1 = len(tags1) - intersec
	exclusive2 = len(tags2) - intersec

	score = min([intersec, exclusive1, exclusive2])
	##print(score)

	return score

def calc_score_from_slide_show(slide_show):
	total_score = 0
	n = len(slide_show) - 1
	for i in range(n):
		tags1 = slide_show[i].tags
		tags2 = slide_show[i + 1].tags

		score = calc_score(tags1, tags2)
		total_score += score		

	return total_score