// gcc -c helloworld.c -o helloworld.o && gcc -o helloworldc helloworld.o && find | ./helloworldc

// also see https://github.com/sarnobat/c_helloworld/tree/master/1_hello_world 

// I can't find a library that requires you to explicitly specify the path to it. glibc seems
// to get found from some well-known place

// Another example that works:
// /Volumes/git/github/c_helloworld/6_exif_library

#include <assert.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	regmatch_t substmatch[1];

 	///
	/// 1) Loop over stdin
	///
	while ((read = getline(&line, &len, stdin)) != -1) {
		
		fprintf( stderr, "[debug] line: %s", line);
		
		regex_t re;
		int compiled = regcomp(&re, "hello([a-bA-Z0-9]*)", REG_EXTENDED|REG_NOSUB);		
		assert (compiled == 0);

		int matchFound = regexec(&re, line, 0, substmatch, 0);
		if  (matchFound == 0) {
		
			///
			/// 1) Print to stdout
			///
			printf("match: %s", line);
		} else if (matchFound == REG_NOMATCH) {
			fprintf( stderr, "[debug] no match: %s", line);
		} else {
			printf("error: %s", line);
		}
	}
 
	free(line);
	exit(EXIT_SUCCESS);
}

