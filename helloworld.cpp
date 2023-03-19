// /Volumes/numerous/usr/local/homebrew/Cellar/gcc/11.3.0_2/bin/g++-11 -I/Volumes/numerous/2022/usr/local/homebrew/Cellar/boost/1.81.0_1/include/ -L /Volumes/numerous/2022/usr/local/homebrew/Cellar/boost/1.81.0_1/lib  -Wall -m64 helloworld.cpp -o helloworld
#include "boost/filesystem.hpp"
#include <string>
#include <iostream>


int main()
{
	///
	/// 5) CLI options
	///
	using namespace std;

	std::string line;
	while (std::getline(std::cin, line)) {
		std::cout << "line: " << line << std::endl;
	}
//	cout << "Hello, World" << endl;


	///
	/// 1) Loop over stdin
	///
	return 0;
}
