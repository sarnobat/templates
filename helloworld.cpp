// /Volumes/numerous/usr/local/homebrew/Cellar/gcc/11.3.0_2/bin/g++-11 -I/Volumes/numerous/2022/usr/local/homebrew/Cellar/boost/1.81.0_1/include/ -L /Volumes/numerous/2022/usr/local/homebrew/Cellar/boost/1.81.0_1/lib/ -l boost_filesystem helloworld.cpp -o helloworld
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
	///
	/// 1) Loop over stdin
	///

	while (std::getline(std::cin, line)) {

		boost::filesystem::path file(line);		
		if (boost::filesystem::exists(line)) {
			std::cout << "exists: " << line << std::endl;
		}
		else {
			std::cout << "does not exist: " << line << std::endl;
		}
	}
	return 0;
}
