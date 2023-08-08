#ifndef  __PMERGEME_HPP__
# define __PMERGEME_HPP__

# include <set>
# include <deque>
# include <ctime>
# include <vector>
# include <string>
# include <climits>
# include <cstdlib>
# include <iostream>
# include <exception>
# include <stdexcept>
# include <sys/time.h>

//-----------------------------------------------------------------------------
std::time_t getTime();
int         toPositiveInt(const std::string& str);
std::string trim(const std::string&, const char*);
//-----------------------------------------------------------------------------

const int LIMIT = 5;

template <typename T>
void print(const T& c)
{
	typename T::const_iterator c_it;
	if (c.size() > LIMIT) {
		for (c_it = c.begin(); c_it < c.begin() + LIMIT - 1; ++c_it) {
			std::cout << *c_it << " ";
		}
		c_it = c.begin();
		std::cout << "[...] " << *(c_it + c.size() - 3)
			<< " " << *(c_it + c.size() - 2)
			<< " " << *(c_it + c.size() - 1);
	} else {
		for (c_it = c.begin(); c_it < c.end(); ++c_it) {
			std::cout << *c_it << " ";
		}
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

template <typename It>
void insertionSort(It begin, It end)
{
	It it1, it2;

	for (it1 = begin + 1; it1 <= end; ++it1) {
			int key = *it1;
			it2 = it1;
			while (it2 > begin && key < *(it2 - 1)) {
				*it2 = *(it2 - 1);
				--it2;
			}
			*it2 = key;
	}
}

template <typename T>
void merge(T& c, int left, int mid, int right)
{
 int n1 = mid - left + 1;
 int n2 = right - mid;
 T L(n1), R(n2);

 for (int i = 0; i < n1; ++i) {
	L[i] = c[left + i];
 }

 for (int i = 0; i < n2; ++i) {
	R[i] = c[mid + i + 1];
 }

 int i = 0, j = 0, k = left;

 while (i < n1 && j < n2) {
	if (L[i] < R[j]) {
		c[k++] = L[i++];
	} else {
		c[k++] = R[j++];
	}
 }

 while (i < n1) {
	c[k++] = L[i++];
 }

 while (j < n2) {
	c[k++] = R[j++];
 }
}

template <typename T>
std::time_t mergeInsertionSort(T& c, int left, int right)
{
	std::time_t time = getTime();
	if (right - left <= LIMIT) {
		insertionSort(c.begin() + left, c.begin() + right);
	} else {
		int mid = left + (right - left) / 2;
		mergeInsertionSort(c, left, mid);
		mergeInsertionSort(c, mid + 1, right);
		merge(c, left, mid, right);
	}
	return (getTime() - time);
}


#endif
