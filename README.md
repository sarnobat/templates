# templates
helloworld templates for each language that you can copy and paste to quickly create prgrams without the delay of warming up your mental cache.

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
