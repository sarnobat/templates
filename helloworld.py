#!/usr/bin/env python3
import fileinput
import sys

file = None;

if (len(sys.argv) == 1):
      file = sys.stdin
else:
      file =  open (sys.argv[-1], "r") # command-line argument

for line in file:
	print ("[info] " + line.strip())