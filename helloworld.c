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
#include <sys/stat.h>
#include <time.h>
#include <search.h>


int main()
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	regmatch_t substmatch[1];

	hcreate(10);

 	///
	/// 1) Loop over stdin
	///
	while ((read = getline(&line, &len, stdin)) != -1) {
		char prefix[10];

		// remove newline
		line[strlen(line)-1] = '\0';
		
		//
		// File path checker
		//
		struct stat sb;
		int isDir  = stat(line, &sb) == 0 && S_ISDIR(sb.st_mode);
		int isFile = stat(line, &sb) == 0 && S_ISREG(sb.st_mode);
		if (isDir) {
			strcpy(prefix,"[dir]");
		} else if (isFile) {
			strcpy(prefix,"[file]");
		} else {
			strcpy(prefix,"[neither]");
		}
		
		//
		// 3) Parse fie path
		//
		gchar* base = g_path_get_basename(line);
		ENTRY item;
		item.key = line;
        item.data = base;

		hsearch(item, ENTER);
		
		//
		// TODO: json parse
		//
		
		const char* pattern = "git(.)";
		const char* input = line;
		const char* replace = "got";
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
		} else if (g_regex_get_capture_count(regex) > 0) {


			//
			// Date
			//
			time_t seconds = time(NULL);
			struct tm *now = localtime(&seconds);
			char timeFormatted[50];
			strftime(timeFormatted, 50, "%A, %B %e, %Y", now);

			ENTRY item1;
			item1.key = line;
			ENTRY *base1 = hsearch(item1, FIND);
			printf("[%s] %6s %30s Replace  %s  in  %30s  by  %s :  %s \n",
				   timeFormatted, prefix, base1->data, pattern, input, replace, result);
		} else {



// 			time_t my_time = time(NULL);
			//printf("%s", ctime(&my_time));


			///
			/// 1) Print to stdout
			///
			fprintf(stderr, "[debug] %s\n", line);
		}
		g_free(result);
		g_regex_unref(regex);

	}
 
	free(line);
	exit(EXIT_SUCCESS);
}

