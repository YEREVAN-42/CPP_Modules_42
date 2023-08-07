#ifndef  __RPN_HPP__
# define __RPN_HPP__

# include <stack>
# include <string>
# include <iostream>
# include <exception>
# include <stdexcept>

class RPN
{
private:
	RPN();
	RPN(const RPN&);

	RPN& operator=(const RPN&);
public:
	RPN(const std::string&);
	~RPN();

public:
	int calculate();

private:
	std::string minput;
};

#endif
