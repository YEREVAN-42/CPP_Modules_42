#ifndef  __EASYFIND_TPP__
# define __EASYFIND_TPP__

# include "easyfind.h"

template <typename T>
void easyfind(const T& container, int value)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end()) {
		throw std::logic_error("integer was not found!");
	}
	std::cout << "The Number ";
	std::cout << *it;
	std::cout << " founded." << std::endl;
}

#endif