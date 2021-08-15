import glob
import os
import sys
import re

info_pattern = r'\[INFO\][^\r\n]*(\n|\r\n)'

template_in_name = 'input.txt'
template_out_name = 'output.txt'
in_files = glob.glob('*' + template_in_name)

cpp_name = sys.argv[1]
tmp_name = 'tmp.txt'

os.system('g++ ' + cpp_name)
for in_file_name in in_files:

	try:
		out_file_name = re.sub(template_in_name, template_out_name, in_file_name)
		expected = open(out_file_name, 'r').read() 
	except FileNotFoundError:
		continue

	os.system(f'cat %s | ./a.out > %s' % (in_file_name, tmp_name))
	received_log = open(tmp_name, 'r').read() 
	received = re.sub(info_pattern, '', received_log)
	
	if(expected.strip() == received.strip()):
		print(f'Test %s ok' % in_file_name)
	else:
		print(f'Test %s not ok' % in_file_name)	
		print(f'received:\n%s' % received_log)	
		print(f'expected:\n%s' % expected)		

	os.system('rm ' + tmp_name)

os.system('rm a.out')
