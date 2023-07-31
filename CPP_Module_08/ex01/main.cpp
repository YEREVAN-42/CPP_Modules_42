#include <iostream>

#include "Span.h"

int main()
{
	Span sp = Span(5);

	try {
		sp.addNumber(1);
		sp.addNumber(3);
		sp.addNumber(56);
		sp.addNumber(-55);
		sp.addNumber(7);

		std::cout << sp.shortestSpan() << std:: endl;
		std::cout << sp.longestSpan() << std:: endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}