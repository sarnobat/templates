#include <stdio.h>
#include <stdlib.h>

// also see https://github.com/sarnobat/c_helloworld/tree/master/1_hello_world 
int main(void)
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
 
// 	stream = fopen("file.txt", "r");
// 	if (stream == NULL)
// 		exit(EXIT_FAILURE);
 
	while ((read = getline(&line, &len, stdin)) != -1) {
		printf("%s", line);
	}
 
	free(line);
// 	fclose(stream);
	exit(EXIT_SUCCESS);
}