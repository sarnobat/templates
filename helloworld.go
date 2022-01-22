//-----------------------------------------------------------------------------------------
// EXAMPLE
//
//   find | go run ~/github/templates.git/helloworld.go
//
//-----------------------------------------------------------------------------------------

package main

import (
	"bufio"
	"fmt"
	"strings"
	"github.com/pborman/getopt"
	"io"
	"log"
	"os"
	"os/exec"
	"path/filepath"
)

var counts = make(map[string]int)

# golang MUST have a main function (unlike python)
func main() {
	//
	// 5) CLI options
	//
	optName := getopt.StringLong("name", 'n', "", "Your name")
	optHelp := getopt.BoolLong("help", 0, "Help")
	getopt.Parse()

	if *optHelp {
		getopt.Usage()
		os.Exit(0)
	}
	fmt.Println("Hello " + *optName)

	//
	// 1) Loop over stdin
	//
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
		p := strings.TrimSpace(s)

		//
		// 3) Parse file path
		//

		if file, err := os.Stat(p); os.IsNotExist(err) {
			if (file == nil) {
				fmt.Println("file is null (dangling symlink?)", p)
				continue

			} else {
				fmt.Print("added: ", p, "\n")
			}
		} else {
			abs, _ := filepath.Abs(p)
			fmt.Println("	absolute: " + abs)
		}

		switch i, err := os.Stat(p); {
		case err != nil:
			fmt.Println(err)
		case i.IsDir():
			fmt.Println(p, "is a directory")
		default:
			fmt.Println(p, "is a file")
		}

		//
		// 6) Call a shell program instead
		//
		cmd := exec.Command("dirname", p)
		out, err := cmd.CombinedOutput()
		if err != nil {
		        log.Fatal(err)
		}
		fmt.Println("	BASENAME: ",strings.Trim(string(out),"\n"),)


		cmd2 := exec.Command("basename", p)
		out2, err2 := cmd2.CombinedOutput()
		if err2 != nil {
		        log.Fatal(err2)
		}
		dirname := strings.Trim(string(out2),"\n")
		fmt.Println("	DIRNAME: ", dirname)

		//
		// 5) dictionary
		//
		_ ,exist := counts[dirname]
		if ! exist {
			counts[dirname] = 1
		} else {
			counts[dirname]++
		}

		// We don't need to check if it's a folder to recurse into. Stdin will ensure that
		// we recurse.
		//if counts
	}
}
