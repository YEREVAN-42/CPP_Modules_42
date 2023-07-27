/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:40:32 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/27 19:12:13 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <exception>

#include "Colors.hpp"

class Base { public:		virtual ~Base() {	}; };
class A : public Base {	};
class B : public Base {	};
class C : public Base {	};

Base* generate()
{
	std::cout << BOLDYELLOW << "Random derive object was geredated!" << RESET << std::endl;
	
	std::srand(time(NULL));
	switch (std::rand() % 3) {
		case (0):
			std::cout << GREEN << "Random   " << CYAN << " A" << RESET << std::endl;
			return new A;
		case (1):
			std::cout << GREEN << "Random   " << CYAN << " B" << RESET << std::endl;
			return new B;
		case (2):
			std::cout << GREEN << "Random   " << CYAN << " C" << RESET << std::endl;
			return new C;
	}
	return NULL;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p)) {
		std::cout << YELLOW << "Type identify via adress: " << GREEN << "A" << RESET << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << YELLOW << "Type identify via adress: " << GREEN << "B" << RESET << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << YELLOW << "Type identify via adress: " << GREEN << "C" << RESET << std::endl;
	}
}

void identify(Base& p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << YELLOW << "Reference\t\t:" << GREEN << " A" << RESET << std::endl;
		return ;
	} catch (...) {	}
		try {
		(void)dynamic_cast<B&>(p);
		std::cout << YELLOW << "Reference\t\t:" << GREEN << " B" << RESET << std::endl;
		return ;
	} catch (...) {	}
		try {
		(void)dynamic_cast<C&>(p);
		std::cout << YELLOW << "Reference\t\t:" << GREEN << " C" << RESET << std::endl;
		return ;
	} catch (...) {	}
}

int main()
{
	Base* randPtr = generate();
	Base& randRef = *randPtr;

	identify(randPtr);
	identify(randRef);

	delete randPtr;

	return 0;
}
