/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:13:57 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/25 17:14:07 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {	}
ScalarConverter::~ScalarConverter() {	}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }

bool ScalarConverter::isChar(const std::string& str)
{ return (1 == str.size() && 0 == std::isdigit(str[0])); }


void    ScalarConverter::convertChar(const std::string &str)
{
    char    c = str[0];
    if (c >= 0 && c <= 127) {
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
	int n = std::atoi(str.c_str());

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

	std::strtof(cStr, &endStr);
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
