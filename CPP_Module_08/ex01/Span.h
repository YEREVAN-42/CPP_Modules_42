#ifndef  __SPAN_H__
# define __SPAN_H__

# include <vector>
# include <exception>
# include <stdexcept>
# include <algorithm>


class Span
{
private:
	typedef std::vector<int>::iterator       iterator;
	typedef std::vector<int>::const_iterator const_iterator;

public:
	Span();
	Span(std::size_t N);
	Span(const Span& other);
	~Span();

	Span& operator=(const Span& other);

public:
	void addNumber(std::size_t N);
	void addNumber(iterator begin, iterator end);

	std::size_t longestSpan();
	std::size_t shortestSpan();

private:
	std::vector<int> mspanVector;
};

#endif
