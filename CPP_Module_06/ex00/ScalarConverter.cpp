/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:13:57 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/27 14:31:29 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {	}
ScalarConverter::~ScalarConverter() {	}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }

bool ScalarConverter::isFinite(float value)
{ return value == value && std::fabs(value) != std::numeric_limits<float>::infinity(); }
bool ScalarConverter::isFinite(double value)
{ return value == value && std::fabs(value) != std::numeric_limits<double>::infinity(); }

bool ScalarConverter::isChar(const std::string& str)
{ return (1 == str.size() && 0 == std::isdigit(str[0])); }


void    ScalarConverter::convertChar(const std::string &str)
{
    char    c = str[0];
    if (c >= 0 && c < 127) {
        if (std::isprint(c) == 0) {
			std::cout << "char:   Non displayable" << std::endl;
		} else {
			std::cout << "char:   " << c << std::endl;
		}
    } else {
    	std::cout << "char:   impossible" << std::endl;
    }
    std::cout << "int:    " << static_cast<int>(c) << std::endl;
    std::cout << "float:  " << static_cast<float>(c)  << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

bool ScalarConverter::isInt(const std::string& str)
{
	std::istringstream iss(str);
	int n;

	iss >> n;
	return (!iss.fail() && iss.eof());
}

void ScalarConverter::convertInt(const std::string& str)
{
	int n = atoi(str.c_str());

	if (n < -128 || n > 127) {
		std::cout << "char:   impossible" << std::endl;
	} else if (n >= 32 && n < 127) {
		std::cout << "char:   " << static_cast<char>(n) <<  std::endl;
	} else {
		std::cout << "char:   Non displayable" << std::endl;
	}
	std::cout << "int:    " << static_cast<int>(n) << std::endl;
	std::cout << "float:  " << static_cast<float>(n) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(n) << ".0" << std::endl;
}

bool ScalarConverter::isFloat(const std::string& str)
{
	const char* cStr = str.c_str();
	char*       endStr;

	strtof(cStr, &endStr);
	if (cStr == endStr) {
		return false;
	}
	while (*endStr != '\0') {
		if (*endStr != 'f') {
			return false;
		}
		++endStr;
	}
	return true;
}


void ScalarConverter::convertFloat(const std::string& str)
{
	float f;

	if (str == "+inf") {
		f = std::numeric_limits<float>::infinity();
	} else if (str == "-inf") {
		f = -std::numeric_limits<float>::infinity();
	} else if (str == "nan") {
		f = std::numeric_limits<float>::quiet_NaN();
	} else {
		f = atof(str.c_str());
	}

	if (isFinite(f) == false) {
		std::cout << "char:   impossible" << std::endl;
		std::cout << "int:    impossible" << std::endl;
	} else {
		char c = static_cast<char>(f);
		if (std::isprint(c)) {
			std::cout << "char:   " << c << std::endl;
		} else {
			std::cout << "char:   Non displayable" << std::endl;
		}
		int n = static_cast<int>(f);
		std::cout << "int:    " << n << std::endl;
	}
	std::cout << "float:  " << f << "f" << std::endl;
  double d = static_cast<double>(f);
	std::cout << "double: " << d << std::endl;
}

bool ScalarConverter::isDouble(const std::string& str)
{
	const char* cStr = str.c_str();
	char*       endStr;

	strtod(cStr, &endStr);
	if (cStr == endStr) {
		return false;
	}
	while (*endStr != '\0') {
		if (*endStr != 'f') {
			return false;
		}
		++endStr;
	}
	return true;
}

void ScalarConverter::convertDouble(const std::string &str)
{
    double  d;

    if (str == "-inf") {
      d = -std::numeric_limits<double>::infinity();
		} else if (str == "+inf") {
      d = std::numeric_limits<double>::infinity();
		} else if (str == "nan") {
      d = std::numeric_limits<double>::quiet_NaN();
		} else {
      d = atof(str.c_str());
		}
    
		char    c = static_cast<char>(d);
    float   f = static_cast<float>(d);
    int     n = static_cast<int>(d);
    
		if (!isFinite(d)) {
        std::cout << "char:   impossible" << std::endl;
        std::cout << "int:    impossible" << std::endl;
    } else {
        if (std::isprint(c)) {
          std::cout << "char:   " << c << std::endl;
				} else {
          std::cout << "char:   Non displayable" << std::endl;
				}
        std::cout << "int:    " << n << std::endl;
    }
    std::cout << "float:  " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(const std::string& str)
{
	if (str.empty()) {
		std::cout << BOLDRED << "Invalid input: empty string" << RESET << std::endl;
	} else if (isInt(str) == true) {
		convertInt(str);
	} else if (isChar(str) == true) {
		convertChar(str);
	} else if (isFloat(str) == true) {
		convertFloat(str);
	} else if (isDouble(str) == true) {
		convertDouble(str);
	} else {
		std::cout << BOLDRED << "Invalid input: " << str << RESET << std::endl;
	}
}
