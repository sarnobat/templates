#include <stdio.h>
#include <stdlib.h>
// gcc -c helloworld.c && gcc -o helloworld helloworld.o && find | helloworld stdin

// also see https://github.com/sarnobat/c_helloworld/tree/master/1_hello_world 
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
 
	while ((read = getline(&line, &len, stdin)) != -1) {
		printf("%s", line);
	}
 
	free(line);
	exit(EXIT_SUCCESS);
}
