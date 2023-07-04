/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 21:05:09 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/01 21:14:25 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

const std::string RESET       = "\033[0m";
const std::string BOLDRED     = "\033[1m\033[31m"; // Bold Red
const std::string BOLDBLUE    = "\033[1m\033[34m"; // Bold Blue
const std::string BOLDCYAN    = "\033[1m\033[36m"; // Bold Cyan
const std::string BOLDBLACK   = "\033[1m\033[30m"; // Bold Black
const std::string BOLDGREEN   = "\033[1m\033[32m"; // Bold Green
const std::string BOLDWHITE   = "\033[1m\033[37m"; // Bold White
const std::string BOLDYELLOW  = "\033[1m\033[33m"; // Bold Yellow
const std::string BOLDMAGENTA = "\033[1m\033[35m"; // Bold Magenta

int main ()
{
	const std::string  str    = "HI THIS IS BRAIN";
	const std::string* strPtr = &str;
	const std::string& strRef = str;

	std::cout << BOLDBLUE << &str << RESET << std::endl;
	std::cout << BOLDGREEN << strPtr << RESET << std::endl;
	std::cout << BOLDYELLOW << &strRef << RESET << std::endl;

	std::cout << BOLDBLUE << str << RESET << std::endl;
	std::cout << BOLDGREEN << *strPtr << RESET << std::endl;
	std::cout << BOLDYELLOW << strRef << RESET << std::endl;
	return 0;
}
