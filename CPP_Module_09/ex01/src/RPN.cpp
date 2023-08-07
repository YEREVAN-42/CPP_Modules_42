#include "./include/RPN.hpp"

RPN::~RPN() {	}
RPN::RPN() : minput("") {	}
RPN::RPN(const RPN& other) : minput(other.minput) {	}
RPN& RPN::operator=(const RPN& other) { (void)other; return *this; }

RPN::RPN(const std::string& input) : minput(input)
{
	if (input.find_first_not_of("-+/* 0987654321") != std::string::npos) {
		throw std::invalid_argument("non valid symbols.");
	}

	for (std::string::iterator it = minput.begin(); it < minput.end(); ++it) {
		if (*it == ' ') {
			minput.erase(it);
			--it;
		}
	}

	if (minput.empty()) {
		throw std::invalid_argument("empty input.");
	}

}

int RPN::calculate()
{
	std::stack<int> stack;

	for (std::string::iterator it = minput.begin(); it < minput.end(); ++it) {
		if (std::isdigit(*it)) {
			stack.push(*it - '0');
		} else {
			if (stack.size() < 2) {
				throw std::invalid_argument("bad format.");
			}

			int a = stack.top();
			stack.pop();
			int b = stack.top();
			stack.pop();

			switch (*it) {
				case '+':
					stack.push(b + a);
					break ;
				case '-':
					stack.push(b - a);
					break ;
				case '*':
					stack.push(b * a);
					break ;
				case '/':
					if (a == 0) {
						throw std::invalid_argument("division by 0.");
					}
					stack.push(b / a);
					break ;
				default :
					throw std::invalid_argument("bad format.");
			}
		}
	}

	if (stack.size() != 1) {
		throw std::invalid_argument("bad format: unfinished calculation.");
	}
	int calculate = stack.top();
	stack.pop();
	return calculate;
}