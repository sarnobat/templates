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
#include <getopt.h>

// Flag set by ‘--verbose’
static int verbose_flag;

void *PrintHello(void *threadid);

int main (int argc, char **argv) {

	

  /* Print any remaining command line arguments (not options). */
//   if (optind < argc)
//     {
//       printf ("non-option ARGV-elements: ");
//       while (optind < argc)
//         printf ("%s ", argv[optind++]);
//       putchar ('\n');
//     }

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

			///
			/// 1) Print to stdout
			///
			fprintf(stderr, "[debug] %s\n", line);
		}
		g_free(result);
		g_regex_unref(regex);

	}

	//
	// CLI Options
	//
	int c;

	while (1) {
		static struct option long_options[] = {
			// These options set a flag.
			{"verbose", 	no_argument,       &verbose_flag, 'v'},
			// These options don’t set a flag.
			// We distinguish them by their indices.
			{"num",			required_argument,       0, 'n'},
			{"help",		no_argument, 0, 'h'},
			{"force",		no_argument, 0, 'f'},
			{0, 0, 0, 0}
		};
		// getopt_long stores the option index here.
		int option_index = 0;

		c = getopt_long (argc, argv, "fhvn:", long_options, &option_index);

		// Detect the end of the options.
		if (c == -1) {
			break;
		}

		switch (c) {
			case 0:
			// If this option set a flag, do nothing else now.
			if (long_options[option_index].flag != 0) {
				break;
			}
			printf ("option %s", long_options[option_index].name);
			if (optarg) {
				printf (" with arg %s", optarg);
			}
			printf ("\n");
			break;

			case 'n':
				printf ("option -n with value `%s'\n", optarg);
				break;

			case 'f':
				puts ("option -f\n");
				break;

			case 'h':
				puts ("option -h\n");
				break;

			case 'v':
				puts ("option -v\n");
				break;

			case '?':
				// getopt_long already printed an error message
				break;

			default:
				abort ();
        }
    }
    
  	// Instead of reporting ‘--verbose’
    // we report the final status resulting from them.
	if (verbose_flag) {
		printf("verbose flag is set: %c\n", verbose_flag);
    }
 
	free(line);

	//
	// 6) Execute shell command
	//	
	FILE *fp;
	char path[1035];

	/* Open the command for reading. */
	fp = popen("uname -a", "r");
	if (fp == NULL) {
		printf("Failed to run command\n" );
		exit(1);
	}

	/* Read the output a line at a time - output it. */
	while (fgets(path, sizeof(path), fp) != NULL) {
		printf("[shell command] %s", path);
	}

	/* close */
	pclose(fp);

	//
	// 8) thread
	//
	int numThreads = 5;
	pthread_t threads[numThreads];
	int rc;
	long t;
	for(t=0;t< numThreads;t++){
		printf("In main: creating thread %ld\n", t);
		rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
		if (rc) {
			printf("ERROR; return code from pthread_create() is %d\n", rc);
			exit(-1);
		}
	}

	/* Last thing that main() should do */
	pthread_exit(NULL);
   
	exit(EXIT_SUCCESS);
}

void *PrintHello(void *threadid)
{
   long tid;
   tid = (long)threadid;
   printf("running thread #%ld\n", tid);
   pthread_exit(NULL);
}