#ifndef  __PMERGEME_HPP__
# define __PMERGEME_HPP__


# include <exception>
# include <stdexcept>

template <typename T>
void print(const T& container)
{
	typename T::const_iterator c_it;
	for (c_it = container.begin(); c_it != container.end(); ++c_it) {
		std::cout << *c_it << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void swap(T& a, T& b)
{
	T c = a;

	a = b;
	b = c;
}

template <typename T>
void insertionSort(T& container)
{
	typename T::iterator it1, it2;

	for (it1 = container.begin() + 1; it1 != container.end(); ++it1) {
		if (*it1 < *(it1 - 1)) {
			std::size_t key = *it1;
			it2 = it1;
			while (it2 != container.begin() && key < *(it2 - 1)) {
				*it2 = *(it2 - 1);
				--it2;
			}
			*it2 = key;
		}
	}
}

#endif
