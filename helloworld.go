//-------------
// EXAMPLE
//
//   find | go run helloworld.go
//
//--------------
package main

import (
	"bufio"
	"fmt"
	"strings"
	//	"path"
	"github.com/pborman/getopt"
	"io"
	"log"
	"os"
	"path/filepath"
)

// echo "hi" | go run main.go
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
		switch i, err := os.Stat(p); {
		case err != nil:
			fmt.Println(err)
		case i.IsDir():
			fmt.Println(p, "is a directory")
		default:
			fmt.Println(p, "is a file")
		}

		if file, err := os.Stat(p); os.IsNotExist(err) {
			fmt.Print("added: ", file.Name(), "\n")
		} else {
			abs, _ := filepath.Abs(s)
			fmt.Println("absolute: " + abs)
		}
	}

}
