//-----------------------------------------------------------------------------------------
// EXAMPLE
//
// g++ helloword.cpp -o helloword
//
// DATE
//
//	2023 Mar 18
//
//-----------------------------------------------------------------------------------------

#include <iostream>

int main() {

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
