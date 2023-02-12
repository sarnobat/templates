import fileinput
for line in fileinput.input():
	print "[info] " + line.strip()