//-----------------------------------------------------------------------------------------
// EXAMPLE
//
//		find | ./helloworld
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
#include <limits.h>

using namespace std;

int main(int argc, char* argv[]) {
	///
	/// 1) Loop over stdin
	///
	std::string line;
	while (std::getline(std::cin, line)) {
		std::string myString = line;
		struct stat buffer;
		if (stat (myString.c_str(), &buffer) == 0) {
			//cout << "exists:\t" << myString << std::endl;
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

			///
			/// 5) dictionary
			///
		} else {
			///
			/// 1) Print to stdout
			///
			cout << "not existing:\t" << myString << std::endl;
		}
	}

	return 0;
}
