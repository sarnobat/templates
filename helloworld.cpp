// /Volumes/numerous/usr/local/homebrew/Cellar/gcc/11.3.0_2/bin/g++-11 -I/Volumes/numerous/2022/usr/local/homebrew/Cellar/boost/1.81.0_1/include/ -L /Volumes/numerous/2022/usr/local/homebrew/Cellar/boost/1.81.0_1/lib/ -l boost_filesystem helloworld.cpp -o helloworld

#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// string filename = "/tmp/";

int main(int argc, char* argv[]) {
	///
	/// 1) Loop over stdin
	///
	std::string line;
	while (std::getline(std::cin, line)) {
		std::string myString = line;
		struct stat buffer;
		if (stat (myString.c_str(), &buffer) == 0) {
			cout << "exists:\t" << myString << std::endl;
		} else {
			cout << "not existing:\t" << myString << std::endl;
		}
	}

	return 0;
}
