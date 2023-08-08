#include "./include/PmergeMe.hpp"

#include <iostream>
#include <exception>
#include <stdexcept>

static void	printInfo(int size, const std::string& name, std::time_t time)
{
	std::cout << "Time to process a range of ";
	std::cout << size << " elements with std::" + name;
	std::cout << " : " << time << " us" << std::endl;
}

int main(int ac, const char* av[])
{
	try {

		if (ac < 2) {
			throw std::invalid_argument("Invalid arguments!");
		}

		std::vector<int>	v;
		std::deque<int>		d;
		std::set<int>		s;

		while (*(++av))	{
			int n = toPositiveInt(*av);
			if (n < 0) {
				throw std::invalid_argument("Invalid arguments!");
			} else {
				if (s.find(n) == s.end())	{
					s.insert(n);
					v.push_back(n);
					d.push_back(n);
				} else {
					std::cout << "Error: duplicate found: " << n << std::endl;
					std::cout << "skipping it" << std::endl;
				}
			}
		}

		std::cout << "Before: ";
		print(v);
		std::time_t	t1, t2;
		t1 = mergeInsertionSort(v, 0, v.size() - 1);
		t2 = mergeInsertionSort(d, 0, d.size() - 1);
		std::cout << "After: ";
		print(v);
		printInfo(v.size(), "vector", t1);
		printInfo(d.size(), "deque", t2);
		
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}