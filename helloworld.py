#-----------------------------------------------------------------------------------------
# EXAMPLE
#
#	find ~/trash/ | python3 helloworld.py
#
# 	cat ~/.zshrc | python3 helloworld.py
#
#	
#	head -40 ~/trash/files_*.txt | python3 /Volumes/git/github/templates.git/helloworld.py     2> /dev/null
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
sizes = {
	100: 0,
	1000 : 0,
	10000 : 0,
	100000 : 0,
	1000000 : 0,
	10000000 : 0,
	100000000 : 0,
	1000000000 : 0,
	10000000000 : 0,
	100000000000 : 0
}
counts_by_size = {
	100: 0,
	1000 : 0,
	10000 : 0,
	100000 : 0,
	1000000 : 0,
	10000000 : 0,
	100000000 : 0,
	1000000000 : 0,
	10000000000 : 0,
	100000000000 : 0
}
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
totalSize = 0
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
		print("[DEBUG] exists: " + fullpath, file=sys.stderr)
#		if Path(line).exists():
		if os.path.isfile(fullpath):
			size = Path(fullpath).stat().st_size
			if size < 100:
				sizes[100] += size
				counts_by_size[100] += 1
			elif size < 1000:
				sizes[1000] += size
				counts_by_size[1000] += 1
			elif size < 10000:
				sizes[10000] += size
				counts_by_size[10000] += 1
			elif size < 100000:
				sizes[100000] += size
				counts_by_size[100000] += 1
			elif size < 1000000:
				sizes[1000000] += size
				counts_by_size[1000000] += 1
			elif size < 100000000:
				sizes[100000000] += size
				counts_by_size[10000000] += 1
			elif size < 1000000000:
				sizes[1000000000] += size
				counts_by_size[1000000000] += 1
			elif size < 10000000000:
				sizes[10000000000] += size
				counts_by_size[10000000000] += 1
			elif size < 100000000000:
				sizes[100000000000] += size
				counts_by_size[100000000000] += 1
			totalSize += size
			print ("[DEBUG] totalSize = " + str(totalSize), file=sys.stderr)


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
		print("[DEBUG] not existing: " + fullpath, file=sys.stderr)
		###
		### 1) Print to stdout
		###
		print ("stdin: " + re.sub(r"^([^\s]*)", r"\033[32m \1 \033[0m", line.rstrip()))
		
		### 2) Regex capture groups extracted and read separately (not used directly
		### in a substitution) will cover more scenarios.
# 		tokens = re.split(r'\.', line)
# 		last_elem = tokens[len(tokens)-1]
#		print (last_elem, end='')


def sizeof_fmt(num, suffix=""):
    for unit in ["", "k", "M", "G", "T", "P", "E", "Z"]:
        if abs(num) < 1024.0:
            return f"{num:3.1f}{unit}{suffix}"
        num /= 1024.0
    return f"{num:.1f}Yi{suffix}"


print("100000000000 size:\t" 	+ sizeof_fmt(sizes[100000000000])	+ "\t(" + str(counts_by_size[100000000000]) + " files)")
print("10000000000 size:\t" 	+ sizeof_fmt(sizes[10000000000]) 	+ "\t(" + str(counts_by_size[10000000000]) + " files)")
print("1000000000 size:\t" 		+ sizeof_fmt(sizes[1000000000]) 	+ "\t(" + str(counts_by_size[1000000000]) + " files)")
print("100000000 size:\t\t" 	+ sizeof_fmt(sizes[100000000]) 		+ "\t(" + str(counts_by_size[100000000]) + " files)")
print("10000000 size:\t\t"	 	+ sizeof_fmt(sizes[10000000]) 		+ "\t(" + str(counts_by_size[10000000]) + " files)")
print("1000000 size:\t\t"	 	+ sizeof_fmt(sizes[1000000]) 		+ "\t(" + str(counts_by_size[1000000]) + " files)")
print("100000 size:\t\t"	 	+ sizeof_fmt(sizes[100000]) 		+ "\t(" + str(counts_by_size[100000]) + " files)")
print("10000 size:\t\t"		 	+ sizeof_fmt(sizes[10000]) 			+ "\t(" + str(counts_by_size[10000]) + " files)")
print("1000 size:\t\t"		 	+ sizeof_fmt(sizes[1000]) 			+ "\t(" + str(counts_by_size[1000]) + " files)")
print("100 size:\t\t" 			+ sizeof_fmt(sizes[100]) 			+ "\t(" + str(counts_by_size[100]) + " files)")
print("Total size: " + sizeof_fmt(totalSize))
