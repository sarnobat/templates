from pathlib import Path

import io
import re
import sys
import argparse
import os

###
### 5) CLI options
###
parser = argparse.ArgumentParser(description='Process some integers.')
parser.add_argument('-n', '--num-max', default=5, type=int,
                    help='an integer for the accumulator')
args = parser.parse_args()

###
### 1) Loop over stdin
###
input_stream = io.TextIOWrapper(sys.stdin.buffer, newline=None, encoding='latin1')
for line in input_stream:

	tokens = re.split("\s", line)
	lastElem = tokens[len(tokens)-1]

	fullpath = line.strip()
	if os.path.exists(fullpath) == True:
		##
		## 3) Parse file path
		##
		parent = Path(line).parent.absolute()
		print (parent)
	else:
		###
		### 1) Print to stdout
		###
		#print(line)
		print ("2: " + re.sub(r"^(.*?)[\s$]", r"\033[32m \1 \033[0m", line.rstrip()))
