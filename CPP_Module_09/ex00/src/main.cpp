#include <string>
#include <fstream>
#include <iostream>
#include <exception>

#include "./include/BitcoinExchange.hpp"

int main(int argc, const char* argv[])
{
	if (argc == 2) {
		std::ifstream file(argv[1]);

		if (file.is_open() == false) {
			std::cerr << "Could not open file." << std::endl;
			return 1;
		}

		try {

			BitcoinExchange(DATABASE).exchange(file);

		} catch (const std::exception& e) {
			file.close();
			std::cerr << e.what() << std::endl;
			return 1;
		}

		file.close();

	} else {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	return 0;
}
