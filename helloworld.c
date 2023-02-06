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
	size_t maxMatches = 2;
	size_t maxGroups = 3;
	regmatch_t groupArray[maxGroups];
	unsigned int m = 0;
	char * cursor;


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


		m = 0;
		cursor = line;
		for (m = 0; m < maxMatches; m ++) {
			if (regexec(&regexCompiled, cursor, maxGroups, groupArray, 0))
			break;  // No more matches

			unsigned int g = 0;
			unsigned int offset = 0;
			for (g = 0; g < maxGroups; g++)
			{
			if (groupArray[g].rm_so == (size_t)-1)
			break;  // No more groups

			if (g == 0)
			offset = groupArray[g].rm_eo;

			char cursorCopy[strlen(cursor) + 1];
			strcpy(cursorCopy, cursor);
			cursorCopy[groupArray[g].rm_eo] = 0;
			printf("Match %u, Group %u: [%2u-%2u]: %s\n",
				 m, g, groupArray[g].rm_so, groupArray[g].rm_eo,
				 cursorCopy + groupArray[g].rm_so);
			}
			cursor += offset;
/*
				int matchFound = regexec(&re, line, 0, groupArray, 0);
				if  (matchFound == 0) {
		// 			int g = 0;		

				// 	printf("match: %s", line);
// 
// 
					unsigned int g = 0;
					unsigned int offset = 0;
// 					for (g = 0; g < maxGroups; g++) {
// 						if (groupArray[g].rm_so == (size_t)-1) {
// 							break;  // No more groups
// 						}
// 				
// 						if (g == 0) {
// 							offset = groupArray[g].rm_eo;
// 						}
// 
// 						char cursorCopy[strlen(cursor) + 1];
// 						strcpy(cursorCopy, cursor);
// 						cursorCopy[groupArray[g].rm_eo] = 0;
// 						printf("Match %u, Group %u: [%2u-%2u]: %s\n",
// 							 m, g, groupArray[g].rm_so, groupArray[g].rm_eo,
// 							 cursorCopy + groupArray[g].rm_so);
// 					}
				} else if (matchFound == REG_NOMATCH) {
					fprintf( stderr, "[debug] no match: %s", line);
				} else {
					printf("error: %s", line);
				}*/
		}
 	}
	free(line);
	exit(EXIT_SUCCESS);
}

