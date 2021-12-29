#-----------------------------------------------------------------------------------------
# EXAMPLE
#
#	find  | python3 helloworld.py
#
# 	cat ~/.zshrc | python3 helloworld.py
#
# COMPILE TO NATIVE
# 	cython --embed helloworld.pyx
# 	gcc -Os -I "/usr/local/homebrew/Cellar/python@3.9/3.9.5/Frameworks/Python.framework/Versions/3.9/include/python3.9" -L "/usr/local/homebrew/Cellar/python@3.9/3.9.5/Frameworks/Python.framework/Versions/3.9/lib/"  helloworld.c -lpython3.9 -o helloworld%
#
# AUTHOR
#
#	Jaya Sharma DDS
#
#-----------------------------------------------------------------------------------------

from pathlib import Path

import io
import re
import sys
import argparse
import os

###
### 5) CLI options
###
parser = argparse.ArgumentParser(description='Example: find  | python3 helloworld.py')
parser.add_argument(
	'-n', '--num-max', default=5, type=int, help='an integer for the accumulator')
args = parser.parse_args()

###
### 1) Loop over stdin
###
input_stream = io.TextIOWrapper(sys.stdin.buffer, newline=None, encoding='latin1')
for line in input_stream:

	fullpath = line.strip()
	if os.path.exists(fullpath):
		##
		## 3) Parse file path
		##
		parent = Path(line).parent.absolute()
		print (parent)
		
		tokens = re.split(r'\.', line)
		last_elem = tokens[len(tokens)-1]
		print (last_elem, end='')

	else:
		###
		### 1) Print to stdout
		###
		print ("stdin: " + re.sub(r"^([^\s]*)", r"\033[32m \1 \033[0m", line.rstrip()))
