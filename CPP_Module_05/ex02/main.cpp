/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:55:38 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/22 21:02:08 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int	main(void)
{
	try {
		AForm	f("f1", 0, 1);
	} catch (const std::exception& e) {
		std::cerr << BOLDRED << "Exception: ❗️ "
			<< BOLDYELLOW << e.what() << RESET << std::endl;
	}

	try {
		AForm	f("f2", 1, 0);
	} catch (const std::exception& e) {
		std::cerr << BOLDRED << "Exception: ❗️ "
			<< BOLDYELLOW << e.what() << RESET << std::endl;
	}

	try {
		AForm	f("f3", 1, 151);
	} catch (const std::exception& e) {
		std::cerr << BOLDRED << "Exception: ❗️ "
			<< BOLDYELLOW << e.what() << RESET << std::endl;
	}

	try {
		AForm	f("f4", 151, 1);
	} catch (const std::exception& e) {
		std::cerr << BOLDRED << "Exception: ❗️ "
			<< BOLDYELLOW << e.what() << RESET << std::endl;
	}

	std::cout << std::endl;

	{
		Bureaucrat	b1("B-1", 1);
		AForm		f("F-5", 150, 150);

		std::cout << f << std::endl;
		b1.signAForm(f);
		std::cout << std::endl << f << std::endl;
	}

	std::cout << std::endl;

	{
		Bureaucrat	b2("B-2", 10);
		AForm		f("F-6", 1, 1);

		std::cout << f << std::endl;
		b2.signAForm(f);
		std::cout << std::endl << f << std::endl;
	}

	return (0);
}