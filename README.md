# templates
helloworld templates for each language that you can copy and paste to quickly create prgrams without the delay of warming up your mental cache.

* r23c: International law requires that all programming tutorials start out with a variation of "hello, world!" as their first example.

TODO: fill in gaps using chatGPT


### Tcl/tk
```tcl
#!/usr/local/bin/wish

proc listDirs {} {
	set output_list [exec seq 1 10]
	foreach dir_base_name $output_list {
		set dir_base_name "$dir_base_name"
		button ".b$dir_base_name" -text "$dir_base_name" 
			-command "puts $dir_base_name"
		pack ".b$dir_base_name"
	}
}

listDirs

```

### Python
```python
import io
import subprocess

for line in io.TextIOWrapper(
		subprocess.Popen(
			"find / -type d | grep proj | grep nl",
			stdout=subprocess.PIPE,
			shell=True)
		.stdout,
		encoding="utf-8"):

	print "[info] " + line.strip()
```

### Go
```go
package main
 
import (
	"bufio"
	"io"
	"log"
	"os"
)
 
func main() {
	in := bufio.NewReader(os.Stdin)
	for {
		s, err := in.ReadString('\n')
		if err != nil {
			// io.EOF is expected, anything else
			// should be handled/reported
			if err != io.EOF {
				log.Fatal(err)
			}
			break
		}
		// Do something with the line of text
		// in string variable s.
		_ = s
	}
}
```

### awk

```awk
BEGIN {

}
/^=+ / {
  print $0
}
```

### Javascript

## Phrase book
https://docs.google.com/spreadsheets/d/1xg_QHbZR0JKY1zQhgyexgtzw9mLe69F-i8Z6Q9AoHkg/edit?usp=sharing

## Programming languages compared
```
=== ===

#programmingtips

Alll the programming languages I know are nice for different reasons

Javascript - elegant map reduce; can be used in browser unlike everything else
Shell - easy to compose
Python - so compact
Java - the compiler weeds out mistakes before runtime
Golang - code is clean

Python is better than nodejs because libraries are more likely to be preinstalled (I think, I could be wrong)

2021-12-23
```

```
=== ===
#visualization
#programmingtips
#programminglanguages

(See if you can depict this as an inverted pyramid)

Wide - Bash
Less wide - Awk
Less wide - Python
Narrow - Golang
Narrowest - C

2023-07-31
```

```
=== first class citizens ===
#programminglanguages
#programmingtips

Bash - everything is a file
SQL - everything is a field
Java - everything is an object
C - everything is a memory pointer

2023-07-31
```

###

| Type of language | modification | execution | example |
|------------------|--------------|------------|--------|
| Scripting language | frequent | rare | Bash, Python, Javascript |
| System/Compiled language | rare | frequent | C, Golang, Java |

Good article: https://web.stanford.edu/~ouster/cgi-bin/papers/scripting.pdf (Scripting: HigherLevel Programming for the 21st Century (John K. Ousterhout))
