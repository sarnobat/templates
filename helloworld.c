// gcc -I/Volumes/numerous/2022/usr/local/homebrew/Cellar/glib/2.72.2/lib/glib-2.0/include/ -I/Volumes/numerous/2022/usr/local/homebrew/Cellar/glib/2.72.2/include/glib-2.0/ -c helloworld.c -o helloworld.o && gcc -o helloworldc /Volumes/numerous/2022/usr/local/homebrew/Cellar/glib/2.72.2/lib/libglib-2.0.dylib helloworld.o && find | ./helloworldc

// also see https://github.com/sarnobat/c_helloworld/tree/master/1_hello_world 

// I can't find a library that requires you to explicitly specify the path to it. glibc seems
// to get found from some well-known place

// Another example that works:
// /Volumes/git/github/c_helloworld/6_exif_library

#include <assert.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

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
		
		const char* pattern = "\n";
		const char* input = line;
		const char* replace = "__NEWLINE__";
		GError* error = NULL;
		GRegex* regex = g_regex_new(pattern, 0, 0, &error);
		if (regex == NULL) {
			fprintf(stderr, "[error] %s\n", error->message);
			g_error_free(error);
			continue;
		}
		char* result = g_regex_replace_literal(regex, input, -1,
											   0, replace, 0, &error);
		if (result == NULL) {
			fprintf(stderr, "%s\n", error->message);
			g_error_free(error);
		} else {

			///
			/// 1) Print to stdout
			///

			printf("Replace pattern '%s' in string '%s' by '%s': '%s'\n",
				   pattern, input, replace, result);
			g_free(result);
		}
		g_regex_unref(regex);

	}
 
	free(line);
	exit(EXIT_SUCCESS);
}

