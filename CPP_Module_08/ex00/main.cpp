#include <iostream>
#include <vector>
#include <list>

#include "easyfind.h"

int main()
{
	//Test for Vector
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	try {
		easyfind<std::vector<int> >(vec, 3);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	//Test for list
	std::list<int> lst;
	lst.push_front(10);
	lst.push_front(20);
	lst.push_front(30);
	lst.push_front(40);
	lst.push_front(50);

	try {
		easyfind<std::list<int> >(lst, 3);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
