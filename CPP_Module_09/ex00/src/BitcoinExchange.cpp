#include "./include/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {	}
BitcoinExchange::~BitcoinExchange() {	}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) { *this = other; }
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) { (void)other; return *this; }

BitcoinExchange::BitcoinExchange(const std::string& dataBaseFilePath)
{
	std::ifstream file(dataBaseFilePath.c_str());

	if (file.is_open() == false) {
		throw std::logic_error("Could not access the database.");
	}

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line)) {
		line = trim(line, " \t\r\v\f");
		if (line.empty() == true) {
			continue ;
		}
		
		std::size_t find = line.find(',');
		if (find == std::string::npos) {
			file.close();
			throw std::logic_error("Database corrupted: " + line);
		}

		try {

			Data        data = trim(line.substr(0, find),  " ,\t\r\v\f");
			std::string rate = trim(line.substr(find + 1), " ,\t\r\v\f");
			
			if (checkFloatNumber(rate) == true) {
				mdata[data] = atof(rate.c_str());
			} else {
				throw std::exception();
			}

		} catch (const std::exception& e) {
			(void)e;
			file.close();
			throw std::logic_error("Database corrupted: " + line);
		}

	}

	file.close();
	if (mdata.empty() == true) {
		throw std::logic_error("Database corrupted: empty database");
	}
}

bool BitcoinExchange::checkFloatNumber(const std::string& number)
{
	if (number.find_first_of('.') != number.find_last_of('.')) {
		return false;
	}

	std::size_t f = number.find_first_not_of("0123456789.");
	std::size_t l = number.find_last_not_of("0123456789.");

	if (f != l) {
		return false;
	}

	if (f != 0 && f != std::string::npos) {
		return false;
	}

	if (f == 0) {
		if (number[f] == '-' || number[f] == '+') {
			return true;
		}
		return false;
	}
	return true;
}

std::string BitcoinExchange::trim(const std::string& line, const char* str)
{
	std::size_t first = line.find_first_not_of(str);
	if (first == std::string::npos) {
		return std::string();
	}
	std::size_t last = line.find_last_not_of(str);
	return std::string(line.substr(first, last - first + 1));
}

void BitcoinExchange::inputError(const std::string& msg)
{ std::cout << "Error: bad input => " << msg << std::endl; }

void BitcoinExchange::valueError(const std::string& msg)
{ std::cout << "Error: " << msg << std::endl; }

//####################################################

void BitcoinExchange::exchange(std::ifstream& file)
{
	std::string line;

	std::getline(file, line);

	while (std::getline(file, line)) {
		if (line.empty()) {
			continue ;
		}

		std::size_t f = line.find("|");
		if (f == std::string::npos) {
			inputError(line);
			continue ;
		}

		std::string data = trim(line.substr(0, f), " \t");
		std::string rate = trim(line.substr(f + 1), " \t");

		if (data.empty() || rate.empty()) {
			inputError(line);
			continue ;
		}

		if (checkFloatNumber(rate) == false) {
			inputError(line);
			continue ;
		}

		try {
			Data d(data);

			float amount = atof(rate.c_str());
			if (amount < 0) {
				valueError("not positive number.");
				continue ;
			} else if (amount > 1000) {
				valueError("too large number.");
				continue ;
			}

			try {
				float price = amount * mdata.at(d);
				std::cout << data << " => " << rate << " = ";
				std::cout << price << std::endl;
			} catch (...) {

				mdata[d] = amount;

				std::map<Data, float>::iterator it = mdata.find(d);
				if (it == mdata.begin()) {
					valueError("no information in database, nor earlier date is available => " + data);
				} else {
					std::cout << data << " => " << rate << " = ";
					std::cout << amount * (--it)->second << std::endl;
					++it;
				}
				mdata.erase(it);
			}

		} catch (const std::exception& e) {
			(void)e;
			inputError(line);
		}
	}
}





// ----------------------------------------------------------------------------

Data::Data(const std::string& strData)
{
	if (strData.size() != 10 || strData[4] != '-' || strData[7] != '-'\
	|| strData.find_first_not_of("-0123456789") != std::string::npos) {
		throw std::exception();
	}

	std::istringstream dayISS(strData.substr(8, 2));
	std::istringstream yearISS(strData.substr(0, 4));
	std::istringstream monthISS(strData.substr(5, 2));

	dayISS   >> mday;
	yearISS  >> myear;
	monthISS >> mmonth;

	int daysInMonth = 31;
	if (mmonth == 4 || mmonth == 6 || mmonth == 9 || mmonth == 11) {
		daysInMonth = 30;
	} else if (mmonth == 2) {
		daysInMonth = 28 + (((myear < 1582) && (myear % 4 == 0))\
			|| ((myear >= 1582) && ((myear % 4 == 0 && myear % 100 != 0) || myear % 400 == 0)));
	}

	if (myear < 1 || mmonth < 1 || mmonth > 12 || mday < 1 || mday > daysInMonth) {
		throw std::exception();
	}
}

int Data::getDay()   const { return mday; }
int Data::getYear()  const { return myear; }
int Data::getMonth() const { return mmonth; }

bool operator==(Data lhs, Data rhs)
{
	if (lhs.getYear() == rhs.getYear() &&\
	lhs.getMonth() == rhs.getMonth() &&\
	lhs.getDay() == rhs.getDay()) {
		return true;
	}
	return false;
}


bool operator>(Data lhs, Data rhs)
{
	if (lhs.getYear() == rhs.getYear() &&\
	lhs.getMonth() == rhs.getMonth() &&\
	lhs.getDay() > rhs.getDay()) {
		return true;
	}

	if (lhs.getYear() == rhs.getYear() &&\
	lhs.getMonth() > rhs.getMonth()) {
		return true;
	}

	if (lhs.getYear() > rhs.getYear()) {
		return true;
	}

	return false;
}

bool operator<(Data lhs, Data rhs)  { return rhs > lhs; }
bool operator>=(Data lhs, Data rhs) { return !(lhs < rhs); }
bool operator<=(Data lhs, Data rhs) { return !(lhs > rhs); }
bool operator!=(Data lhs, Data rhs) { return !(lhs == rhs); }
 
std::ostream& operator<<(std::ostream& out, const Data& data)
{
	out << data.getYear() << "-" << data.getMonth() << "-" << data.getDay();

	return out;
}

