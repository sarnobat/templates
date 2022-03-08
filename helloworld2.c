#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
// gcc -c helloworld2.c && gcc -o helloworld2c helloworld2c.o && find | ./helloworld2c stdin

int main()
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
 
	while ((read = getline(&line, &len, stdin)) != -1) {
		printf("from c: %s", line);
		regex_t re;
		int i = regcomp(&re, "hello([a-bA-Z0-9]*)", REG_EXTENDED|REG_NOSUB);
	}
 
	free(line);
	exit(EXIT_SUCCESS);
}

