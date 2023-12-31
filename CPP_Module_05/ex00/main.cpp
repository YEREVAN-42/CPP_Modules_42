/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:55:38 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/22 17:09:52 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat	Armenia("Armenia", 15);
	Bureaucrat	Russia("Russia", 140);
	Bureaucrat	India("India", 1);

	std::cout << Armenia << std::endl;
	std::cout << Russia << std::endl;
	std::cout << India << std::endl;

	try {
		Bureaucrat	Iran("Iran", 151);
	} catch (const std::exception& e) {
		std::cerr << BOLDRED << "Exception: ❗️ "
			<< BOLDYELLOW << e.what() << RESET << std::endl;
	}

	try {
		Bureaucrat	Iraq("Iraq", 0);
	} catch (const std::exception& e) {
		std::cerr << BOLDRED << "Exception: ❗️ "
			<< BOLDYELLOW << e.what() << RESET << std::endl;
	}

	try {
		Armenia.increment();
		Russia.decrement();
	} catch (const std::exception& e) {
		std::cerr << BOLDRED << "Exception: ❗️ "
			<< BOLDYELLOW << e.what() << RESET << std::endl;
	}

	std::cout << Armenia << std::endl;
	std::cout << Russia << std::endl;

	return (0);
}