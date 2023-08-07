#include "./include/PmergeMe.hpp"

#include <iostream>
#include <exception>
#include <stdexcept>

int main(int ac, const char* av[])
{
	try {

		if (ac < 2) {
			throw std::invalid_argument("Invalid arguments!");
		}

		

	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}