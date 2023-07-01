/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 10:14:39 by khovakim          #+#    #+#             */
/*   Updated: 2023/06/30 17:20:10 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

bool OnlyDigits(const std::string& str)
{
	for (std::size_t i = 0; i < str.size(); ++i) {
		if (std::isdigit(static_cast<int>(str[i])) == 0) {
			return false;
		}
	}
	return true;
}

bool OnlyLetters(const std::string& str)
{
	for (std::size_t i = 0; i < str.size(); ++i) {
		if (std::isalpha(static_cast<int>(str[i])) == 0) {
			return false;
		}
	}
	return true;
}

std::string ReSize(std::string str)
{
	if (str.size() > 10) {
		str.erase(str.begin() + 9, str.end());
		str += '.';
	}
	return str;
}

void Input(std::string& str, const std::string& massige)
{
	std::cout << CYAN << massige << WHITE;
	do {
		std::getline(std::cin, str);
		if (std::cin.eof()) {
			break ;
		}
		if (str.empty()) {
			std::cout << RED << "Empty line, try again" << std::endl << WHITE;
		}
	} while (str.empty());
}

void Input(std::string& str, const std::string& massige,\
		bool (*checker)(const std::string&))
{
	std::cout << CYAN << massige << WHITE;
	do {
		std::getline(std::cin, str);
		if (std::cin.eof()) {
			break ;
		}
		if (str.empty()) {
			std::cout << RED << "Empty line, try again" << std::endl << WHITE;
		} else if (checker(str) == false) {
			std::cout << RED << "Invalid input, try again" << std::endl << WHITE;
		}
	} while (str.empty() || checker(str) == false);
}

