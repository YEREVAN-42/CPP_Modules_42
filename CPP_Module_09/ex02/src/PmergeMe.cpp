#include "./include/PmergeMe.hpp"

std::string trim(const std::string& line, const char* str)
{
	std::size_t first = line.find_first_not_of(str);
	if (first == std::string::npos) {
		return std::string("");
	}
	std::size_t last = line.find_last_not_of(str);
	return std::string(line.substr(first, last - first + 1));
}

std::time_t getTime()
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	// return (tv.tv_sec * 1000 + tv.tv_usec / 1000); //milisecond
	return (tv.tv_sec * 1000 * 1000 + tv.tv_usec); //microsecond
}

int toPositiveInt(const std::string& str)
{
	const std::string number = trim(str, " \t\r\v\f\n");

	if (number.empty()) {
		return -1;
	}

	std::size_t f = number.find_first_not_of("0123456789");
	std::size_t l = number.find_last_not_of("0123456789");

	if (f != l) {
		return -1;
	}

	if (f != 0 && f != std::string::npos) {
		return -1;
	}

	if (f == 0 && number[f] != '+') {
		return -1;
	}

	double n = atof(number.c_str());
	double m = INT_MAX;

	if (n > m) {
		return -1;
	}

	return atoi(number.c_str());
}