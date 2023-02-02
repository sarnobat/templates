// gcc -c helloworld2.c -o helloworld2c.o && gcc -o helloworld2c helloworld2c.o && find | ./helloworld2c

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
 
	while ((read = getline(&line, &len, stdin)) != -1) {
		
		fprintf( stderr, "[debug] %s", line);
		
		regex_t re;
		int compiled = regcomp(&re, "hello([a-bA-Z0-9]*)", REG_EXTENDED|REG_NOSUB);		
		assert (compiled == 0);

		int matchFound = regexec(&re, line, 0, NULL, 0);
// 		printf("%s\n", compared);
		if  (matchFound == 0) {
			printf("match: %s", line);
		} else if (matchFound == REG_NOMATCH) {
//			printf("no match: %s", line);
		} else {
			printf("error: %s", line);
		}
	}
 
	free(line);
	exit(EXIT_SUCCESS);
}

