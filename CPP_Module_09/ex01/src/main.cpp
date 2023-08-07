#include <iostream>

#include "./include/RPN.hpp"

int main(int ac, const char* av[])
{
	if (ac != 2) {
		std::cout << "Invalid arguments!" << std::endl;
		return 1;
	}

	try {

		RPN calculator(av[1]);

		std::cout << calculator.calculate() << std::endl;
	} catch (const std::exception& e) {

		std::cout << "Error: " << e.what() << std::endl;

	}

	return 0;
}
