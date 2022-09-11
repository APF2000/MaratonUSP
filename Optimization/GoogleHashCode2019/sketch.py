# https://storage.googleapis.com/coding-competitions.appspot.com/HC/2019/hashcode2019_qualification_task.pdf

# Judge: https://github.com/wbigger/google-hashcode-2019

from models import Pic, Slide
from calculations import *
from optimizations import *

f_is_vertical = lambda a : a == 'V'

n = int(input()) # photos
pics = []
for i in range(n):
	pic_info = input().split()
	is_vertical = f_is_vertical(pic_info[0])
	#n_tags = int(pic_info[1])

	tags = set(pic_info[2:])

	pics.append( Pic(is_vertical, tags, i) )

####print(pics)
print("upper bound points: " + str(upper_bound(pics)))
slide_show = optimize_genetic(pics)
print( calc_score_from_slide_show(slide_show) )
