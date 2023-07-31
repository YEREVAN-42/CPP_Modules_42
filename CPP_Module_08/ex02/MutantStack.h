#ifndef  __MUTANTSTACK_H__
# define __MUTANTSTACK_H__

# include <stack>
# include <deque>

template <class T>
class MutantStack : public std::stack<T, std::deque<T> >
{
public:
	typedef typename std::deque<T>::iterator iterator;
	typedef typename std::deque<T>::const_iterator const_iterator;

public:
	MutantStack() : std::stack<T, std::deque<T> >() {	}

public:
	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

#endif
