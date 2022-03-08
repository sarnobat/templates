#include <assert.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
// gcc -c helloworld2.c && gcc -o helloworld2c helloworld2c.o && find | ./helloworld2c stdin
// I can't find a library that requires you to explicitly specify the path to it. glibc seems
// to get found from some well-known place
int main()
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
 
	while ((read = getline(&line, &len, stdin)) != -1) {
		printf("from c: %s", line);
		regex_t re;
		int i = regcomp(&re, "hello([a-bA-Z0-9]*)", REG_EXTENDED|REG_NOSUB);		
		assert (i == 0);
		
		 i = regexec(&re, "hello42world",0,NULL,0);
	}
 
	free(line);
	exit(EXIT_SUCCESS);
}

