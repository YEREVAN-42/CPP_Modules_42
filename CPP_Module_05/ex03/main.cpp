/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:55:38 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/25 02:01:06 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	Intern	intern;
	AForm	*f;

	f = intern.makeForm("shrubbery creation", "28C");
	std::cout << *f << std::endl;
	delete f;

	f = intern.makeForm("robotomy request", "28B");
	std::cout << *f << std::endl;
	delete f;

	f = intern.makeForm("presidential pardon", "28A");
	std::cout << *f << std::endl;
	delete f;

	f = intern.makeForm("undefined", "0U");

	return (0);
}