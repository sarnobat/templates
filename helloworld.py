#-----------------------------------------------------------------------------------------
# EXAMPLE
#
#	find ~/trash/ | python3 helloworld.py
#
# 	cat ~/.zshrc | python3 helloworld.py
#
# COMPILE TO NATIVE
# 	cython --embed helloworld.pyx
# 	gcc -Os -I "/usr/local/homebrew/Cellar/python@3.9/3.9.5/Frameworks/Python.framework/Versions/3.9/include/python3.9" -L "/usr/local/homebrew/Cellar/python@3.9/3.9.5/Frameworks/Python.framework/Versions/3.9/lib/"  helloworld.c -lpython3.9 -o helloworld%
#
# DATE
#
#	2022 Jan 10
#
# AUTHOR
#
#	Jaya Sharma DDS
#
#-----------------------------------------------------------------------------------------

from subprocess import run

import argparse
import io
import os
import re
import sys

from pathlib import Path

# TODO: wrap this in a main function like the golang one, to show how to declare and call functions

counts = {}

###
### 5) CLI options
###
parser = argparse.ArgumentParser(description='Example: find  | python3 helloworld.py')
parser.add_argument(
	'-n', '--num-max', default=5, type=int, help='maximum files per directory')
args = parser.parse_args()

###
### 1) Loop over stdin
###
input_stream = io.TextIOWrapper(sys.stdin.buffer, newline=None, encoding='latin1')
for line in input_stream:

	fullpath = line.strip()
	# TODO: do we need to check if it exists? For the ultimate use case, I guess so.
	# But if we're using relative paths (e.g. for striped videos dirs) this might be
	# undersirable
	if os.path.exists(fullpath):
		##
		## 3) Parse file path
		##
		
		# TODO: check if it's a file or a dir (which shell can't do so compactly)
		# get absolute path
		parent = Path(line).parent.absolute()
		print (parent)


		##
		## 6) Call a shell program instead
		##
		
		# Note: these work even if the file doesn't exist
		dirname = run(["dirname",line], capture_output=True).stdout.decode("utf-8").strip()
		basename = run(["basename",line], capture_output=True).stdout.decode("utf-8").strip()

#		print (counts)

		##
		## 5) dictionary
		##
		if not dirname in counts:
			counts[dirname] = 1
		else:
			counts[dirname] += 1
		
		# We don't need to check if it's a folder to recurse into. Stdin will ensure that
		# we recurse.
		if counts[dirname] <= args.num_max:
			print (line.strip(), end="\n")

	else:
		###
		### 1) Print to stdout
		###
		print ("stdin: " + re.sub(r"^([^\s]*)", r"\033[32m \1 \033[0m", line.rstrip()))
		
		### 2) Regex capture groups extracted and read separately (not used directly
		### in a substitution) will cover more scenarios.
# 		tokens = re.split(r'\.', line)
# 		last_elem = tokens[len(tokens)-1]
#		print (last_elem, end='')
