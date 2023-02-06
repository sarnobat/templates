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
#include <string.h>

int main()
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	size_t maxGroups = 3;
	regmatch_t groupArray[maxGroups];

 	///
	/// 1) Loop over stdin
	///
	while ((read = getline(&line, &len, stdin)) != -1) {

		///
		/// 1) Print to stdout or stderr
		///		
		fprintf( stderr, "[debug] line: %s", line);
		
		regex_t re;
		int compiled = regcomp(&re, "hello([a-bA-Z0-9]*)", REG_EXTENDED|REG_NOSUB);		
		assert (compiled == 0);

		int matchFound = regexec(&re, line, 0, groupArray, 0);
		if  (matchFound == 0) {
			int g = 0;		

			printf("match: %s", line);

			for (g = 0; g < maxGroups; g++) {
				if (groupArray[g].rm_so == (size_t)-1) {
					break;  // No more groups
				}

				char sourceCopy[strlen(line) + 1];
				strcpy(sourceCopy, line);
// 				sourceCopy[groupArray[g].rm_eo] = 0;
// 				printf("Group %u: [%2ld-%2ld]: %s\n",
// 					g, groupArray[g].rm_so, groupArray[g].rm_eo,
// 					sourceCopy + groupArray[g].rm_so);
			}
		} else if (matchFound == REG_NOMATCH) {
			fprintf( stderr, "[debug] no match: %s", line);
		} else {
			printf("error: %s", line);
		}
	}
 
	free(line);
	exit(EXIT_SUCCESS);
}

