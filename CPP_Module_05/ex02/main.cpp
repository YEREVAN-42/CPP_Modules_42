/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:55:38 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/25 01:17:11 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	ShrubberyCreationForm	s1("s1");
	RobotomyRequestForm		r1("r1");
	PresidentialPardonForm	p1("p1");

	Bureaucrat				b1("b1", 145);
	Bureaucrat				b2("b2", 137);
	Bureaucrat				b3("b3", 1);

	std::cout << b1 << std::endl << b2 << std::endl << b3 << std::endl;

	std::cout << std::endl << s1 << std::endl;

	b3.executeAForm(s1);
	b1.signAForm(s1);
	b1.executeAForm(s1);
	b2.executeAForm(s1);
	b3.executeAForm(s1);
	std::cout << s1 << std::endl;

	std::cout << std::endl;

	std::cout << r1 << std::endl;
	b2.signAForm(r1);
	b3.signAForm(r1);
	b3.executeAForm(r1);
	b3.executeAForm(r1);
	b3.executeAForm(r1);

	std::cout << std::endl;

	std::cout << p1 << std::endl;
	b3.signAForm(p1);
	b3.executeAForm(p1);

	return (0);
}