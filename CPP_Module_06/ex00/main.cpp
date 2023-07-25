/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:12:48 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/25 17:21:32 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, const char* argv[])
{
	if (2 == argc) {
		const std::string argument(argv[1]);
		ScalarConverter::convert(argument);
	} else {
		std::cout << BOLDRED << "❌ ./scalar [argument]" << RESET << std::endl;
	}
	return 0;
}
