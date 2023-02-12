#include <stdio.h>
#include <stdlib.h>
// gcc -c helloworld.c && gcc -o helloworldc helloworld.o && find | ./helloworldc stdin
// also see https://github.com/sarnobat/c_helloworld/tree/master/1_hello_world 

// I can't find a library that requires you to explicitly specify the path to it. glibc seems
// to get found from some well-known place

// Another example that works:
// /Volumes/git/github/c_helloworld/6_exif_library
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
 
	while ((read = getline(&line, &len, stdin)) != -1) {
		printf("from c: %s", line);
	}
 
	free(line);
	exit(EXIT_SUCCESS);
}
