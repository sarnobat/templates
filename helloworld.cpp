//-----------------------------------------------------------------------------------------
// EXAMPLE
//
//		find	| ./helloworld
//		du		| ./helloworld
//
// COMPILE TO NATIVE
//
//		/Volumes/numerous/usr/local/homebrew/Cellar/gcc/11.3.0_2/bin/g++-11 -I/Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk/usr/include/ -I/Volumes/numerous/2022/usr/local/homebrew/Cellar/boost/1.81.0_1/include/ -L /Volumes/numerous/2022/usr/local/homebrew/Cellar/boost/1.81.0_1/lib/ -l boost_filesystem helloworld.cpp -o helloworld
//
// DATE
//
//		2022 Jan 20
//
//-----------------------------------------------------------------------------------------

#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <limits.h>

using namespace std;

using namespace std;

string exec(string command) {
   char buffer[128];
   string result = "";

   // Open pipe to file
   FILE* pipe = popen(command.c_str(), "r");
   if (!pipe) {
      return "popen failed!";
   }

   // read till end of process:
   while (!feof(pipe)) {

      // use buffer to read and add to result
      if (fgets(buffer, 128, pipe) != NULL)
         result += buffer;
   }

   pclose(pipe);
   return result;
}

int main(int argc, char* argv[]) {
	///
	/// 1) Loop over stdin
	///
	std::string line;
	while (std::getline(std::cin, line)) {
		std::string myString = line;
		struct stat buffer;
		if (stat (myString.c_str(), &buffer) == 0) {

			// check if it's a file or a dir
			if (S_ISREG(buffer.st_mode)) {
				cout << "file:\t" << myString << std::endl;
			} else if (S_ISDIR(buffer.st_mode)) {
				cout << "dir:\t" << myString << std::endl;
			}
			// get absolute path
			char resolved_path[PATH_MAX]; 
			realpath(myString.c_str(), resolved_path);
			cout << "abs:\t" << resolved_path << std::endl;

			///
			/// 6) Call a shell program instead
			///
			std::string cmd = std::string("dirname ") + myString;

			char buffer[128];
			string result = "";

			FILE* pipe = popen(cmd.c_str(), "r");
			if (pipe) {
				while (!feof(pipe)) {
				  if (fgets(buffer, 128, pipe) != NULL)
					 result += buffer;
				}
				pclose(pipe);			
				cout << "dirname output: " << result << "\n";
			}

			///
			/// 5) dictionary
			///
		} else {
			///
			/// 1) Print to stdout
			///
			cout << "not a file path:\t" << myString << std::endl;

			///
			/// 2) Regex capture groups extracted and read separately (not used directly
			/// in a substitution) will cover more scenarios.
			///
			std::regex rgx("^([0-9]*)\\s(.*)");
			std::smatch matches;

			if (std::regex_search(myString, matches, rgx)) {
				std::cout << "\tMatch found\n";

				for (size_t i = 0; i < matches.size(); ++i) {
				std::cout << "\t" << i << ": '" << matches[i].str() << "'\n";
				}
			} else {
				// no match
				std::cout << "Match not found\n";
			}
		}
	}

	return 0;
}
