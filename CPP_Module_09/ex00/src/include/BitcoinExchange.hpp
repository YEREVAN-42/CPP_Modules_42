#ifndef  __BITCOINEXCHANGE_HPP__
# define __BITCOINEXCHANGE_HPP__

# include <map>
# include <string>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <cstdlib>
# include <iostream>
# include <exception>

struct Data
{
public:
	Data(const std::string& strData);

	int getDay()   const;
	int getYear()  const;
	int getMonth() const;

private:
	int myear;
	int mmonth;
	int mday;
};

bool operator==(Data lhs, Data rhs);
bool operator!=(Data lhs, Data rhs);
bool operator>=(Data lhs, Data rhs);
bool operator<=(Data lhs, Data rhs);
bool operator>(Data lhs, Data rhs);
bool operator<(Data lhs, Data rhs);

std::ostream& operator<<(std::ostream& out, const Data& data);

//-------------------------------------------------------------------

const std::string DATABASE = "./src/resources/data.csv";

class BitcoinExchange
{
private:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);

	BitcoinExchange& operator=(const BitcoinExchange& other);

public:
	BitcoinExchange(const std::string& dataBaseFilePath);
	~BitcoinExchange();


public:
	void exchange(std::ifstream& file);

private:
	// std::string removeTrailingZero(float number);
	std::string trim(const std::string& line, const char* str);
	bool checkFloatNumber(const std::string& number);

	void inputError(const std::string& msg);
	void valueError(const std::string& msg);

private:
	std::map<Data, float> mdata;
};

#endif
