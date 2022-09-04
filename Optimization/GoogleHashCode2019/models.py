
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
		self.pics = pics

	def __str__(self):
		return str(self.tags)

	def __repr__(self):
		return str(self.tags)

	# def has_verticals(self):
	# 	return ( len(self.pics) > 1 )

